#include <iostream>
#include<vector>
using namespace std;

int const MAXN = 5e5+2;
int const level = 18;
vector <int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];
int number_of_elements_in_subtree[MAXN];
int n, m;
int a, b;

void dfs(int cur, int prev){

    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    number_of_elements_in_subtree[cur] = 1;
    for (int i=0; i<tree[cur].size(); i++){

        if (tree[cur][i] != prev) {
            dfs(tree[cur][i], cur);
            number_of_elements_in_subtree[cur] += number_of_elements_in_subtree[tree[cur][i]];
        }
    }
}

void precomputeSparseMatrix(int n){
    dfs(1, 0);

    for (int i=1; i<level; i++){

        for (int node = 1; node <= n; node++){

            if (parent[node][i-1] != -1)
                parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
}

int lca(int u, int v){

    if (depth[v] < depth[u])
        swap(u, v);

    int diff = depth[v] - depth[u];

    for (int i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];

    if (u == v)
        return u;

    for (int i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }

    return parent[u][0];
}

void addEdge(int u,int v){

    tree[u].push_back(v);
    tree[v].push_back(u);
}

void load_data(){
    cin >> n;
    for(int i = 0; i <n-1; i++){
        cin >> a >> b;
        addEdge(a, b);
    }
}

void answer_questions(){

    cin >> m;
    while(m--){
        cin >> a >> b;

        if(a == b){
            cout << n << endl;
        }
        else if(!((depth[a] + depth[b] - 2 * depth[lca(a, b)])%2)){
            if(depth[a] == depth[b]){
                int u = a;
                int v = b;
                for (int i=level-1; i>=0; i--)
                    if (parent[u][i] != parent[v][i]){
                        u = parent[u][i];
                        v = parent[v][i];
                    }
                cout << n-number_of_elements_in_subtree[u]-number_of_elements_in_subtree[v] << endl;
            }
            else{
                int v;
                if(depth[a] > depth[b]){
                    v = a;
                }
                else{
                    v = b;
                }

                int actual_lca = lca(a, b);
                int distance = depth[a] + depth[b] - 2 * depth[actual_lca];
                int diff = distance/2-1;
                for (int i=0; i<level; i++)
                    if ((diff>>i)&1)
                        v = parent[v][i];

                cout << number_of_elements_in_subtree[parent[v][0]] - number_of_elements_in_subtree[v] << endl;

            }
        }
        else{
            cout << 0 << endl;
        }
    }
}

int main()
{
    load_data();
    precomputeSparseMatrix(n);
    answer_questions();
}