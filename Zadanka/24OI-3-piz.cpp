#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int const M = 1e5+3;

int n, k;
int a, b, c;
map<int, int> graph[M];
long long up[M], down[M];
int parents[M];
vector<int> interesting_nodes;
long long result;
int possible_savings[M];
long long graph_weight;
vector<int> leaf_nodes;
long long Tp_weight;
long long P_weight;
bool visited[M];

void load_data(){
    cin >> n >> k;
    graph_weight = 0;
    int i = n;
    while(--i){
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
        graph_weight += c;
    }
}

void DFS_with_assign_parent(int parent){
    for(auto child:graph[parent]){
        if(child.first != parents[parent]) {
            parents[child.first] = parent;
            DFS_with_assign_parent(child.first);
        }
    }
}

void find_parents(){
    DFS_with_assign_parent(1);
}

void find_interesting_nodes(){
    for(int i = 2; i < M; i++){
        if(graph[i].size() == 1){
            interesting_nodes.push_back(i);
        }
    }
}

void make_down_list(int node, long long actual_down){
    down[node] = max(down[node], actual_down);
    if(node != parents[node]){
        make_down_list(parents[node], actual_down + graph[node][parents[node]]);
    }
}

void make_up_list(int node, long long actual_up){
    up[node] = actual_up;
    if(down[node] != 0){
        for(auto child:graph[node]){
            if(child.first != parents[node]){
                make_up_list(child.first, actual_up+child.second);
            }
        }
    }
    else{
        leaf_nodes.push_back(node);
    }
}

void make_up_and_down_lists(){
    for(auto node:interesting_nodes){
        make_down_list(node, 0);
    }
    make_up_list(1, 0);
}

void make_possible_savings(){
    for(int i = 2; i <= n; i++){
        possible_savings[i] = -up[parents[i]] + graph[i][parents[i]] + down[i];
    }
}

bool the_key(const int item1, const int item2){
    return possible_savings[item1] > possible_savings[item2];
}

void find_result(){

    sort(leaf_nodes.begin(), leaf_nodes.end(), the_key);

    while(k < leaf_nodes.size()){
        leaf_nodes.pop_back();
    }

    visited[1] = true;

    int actual_node;
    for(auto node:leaf_nodes){
        P_weight += up[node];
        actual_node = node;
        while(!visited[actual_node]) {
            visited[actual_node] = true;
            Tp_weight += graph[actual_node][parents[actual_node]];
            actual_node = parents[actual_node];
        }
    }
    result = 2 * (graph_weight - Tp_weight) + P_weight;
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    parents[1] = 1;
    find_parents();
    find_interesting_nodes();
    make_up_and_down_lists();
    make_possible_savings();
    find_result();
}