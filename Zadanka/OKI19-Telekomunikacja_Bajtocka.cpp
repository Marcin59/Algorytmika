#include <iostream>
#include<vector>
using namespace std;

int const MAXN = 1e5+2;
int const level = 18;
vector <int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];
int n;
int a, b, c;
int questions;

void dfs(int cur, int prev){

    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i=0; i<tree[cur].size(); i++){

        if (tree[cur][i] != prev)
            dfs(tree[cur][i], cur);
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

int find_distance(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void load_data(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        addEdge(a, b);
    }
    precomputeSparseMatrix(n);
}

void answer_questions(){
    cin >> questions;
    while(questions--){
        cin >> a >> b >> c;
        if(find_distance(a, b) == find_distance(a, c) + find_distance(b, c)){
            cout << "TAK" << endl;
        }
        else{
            cout << "NIE" << endl;
        }
    }
}

int main()
{
    load_data();
    answer_questions();
}