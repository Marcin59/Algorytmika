#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

#define MAXN 500003
#define level 19

vector<pair<int, int>> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];
int max_in_subtree[MAXN][level];
int n;
int a, b, c;

void dfs(int cur, int prev){

    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for(const auto& item: tree[cur]) {
        if (item.first != prev) {
            max_in_subtree[item.first][0] = item.second;
            dfs(item.first, cur);
        }
    }
}

void precomputeSparseMatrix(int n){
    dfs(1, 0);

    for (int i=1; i<level; i++){

        for (int node = 1; node <= n; node++){

            if (parent[node][i-1] != -1) {
                parent[node][i] = parent[parent[node][i - 1]][i - 1];
                max_in_subtree[node][i] = max(max_in_subtree[node][i-1], max_in_subtree[parent[node][i - 1]][i-1]);
            }
        }
    }
}

int lca(int u, int v){

    int max_in_way = INT_MIN;
    if(u == v) return 0;
    if (depth[v] < depth[u])
        swap(u, v);

    int diff = depth[v] - depth[u];

    for (int i=0; i<level; i++)
        if ((diff>>i)&1) {
            max_in_way = max(max_in_subtree[v][i], max_in_way);
            v = parent[v][i];
        }

    if (u == v)
        return max_in_way;

    for (int i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i]){
            max_in_way = max(max_in_subtree[u][i], max_in_way);
            max_in_way = max(max_in_subtree[v][i], max_in_way);
            u = parent[u][i];
            v = parent[v][i];
        }
    max_in_way = max(max_in_subtree[u][0], max_in_way);
    max_in_way = max(max_in_subtree[v][0], max_in_way);
    return max_in_way;
}

void addEdge(int u,int v, int value){

    tree[u].emplace_back(v, value);
    tree[v].emplace_back(u, value);
}

void load_data(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    precomputeSparseMatrix(n);
}

void make_answer(){
    while(cin >> a && a != -1){
        cin >> b;
        cout << lca(a, b) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_answer();
}