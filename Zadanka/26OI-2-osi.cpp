#include<iostream>
#include<map>
#include<vector>

using namespace std;

int n, m;
int a, b;

int const N_LIMIT = 1e6+2;
vector<pair<int, int>> ways;
map<int ,map<int, int>> undirected_graph;
map<int, map<int, bool>> directed_graph;
map<int, map<int, bool>> directed_inverce_graph;
map<int, bool> visited;
vector<int> stack;
int result = 0;

void load_data(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        ways.emplace_back(a, b);
        undirected_graph[a][b]++;
        undirected_graph[b][a]++;
    }
}

void DFS_to_make_graph(int node, int parent){
    visited[node] = true;
    int child;
    for(auto data:undirected_graph[node]){
        child = data.first;
        if(!visited[child]){
            directed_graph[node][child] = true;
            directed_inverce_graph[child][node] = true;
            DFS_to_make_graph(child, node);
        }
        else if(!directed_graph[child][node] || data.second > 1){
            directed_graph[node][child] = true;
            directed_inverce_graph[child][node] = true;
        }
    }
}


void make_directed_graph(){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS_to_make_graph(i, i);
        }
    }
}

void DFS_first(int node){
    visited[node] = true;
    for(auto child:directed_graph[node]){
        if(!visited[child.first]){
            DFS_first(child.first);
        }
    }
    stack.push_back(node);
}

void DFS_second(int node){
    visited[node] = true;
    for(auto child:directed_inverce_graph[node]){
        if(!visited[child.first]){
            DFS_second(child.first);
        }
    }
}

void Kosaraju_algorithm(){
    visited.clear();
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS_first(i);
        }
    }
    visited.clear();
    int actual_node;
    while(!stack.empty()){
        actual_node = stack.back();
        stack.pop_back();
        if(!visited[actual_node]){
            DFS_second(actual_node);
            result++;
        }
    }
}

void print_answer(){
    cout << result << endl;
    for(auto side:ways){
        if(directed_graph[side.first][side.second]){
            cout << "<";
        }
        else{
            cout << ">";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_directed_graph();
    Kosaraju_algorithm();
    print_answer();
}