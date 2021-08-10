#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>

using namespace std;

const int N_LIMIT = 1e4+4;
unordered_map<int, bool> visited;
vector<int> graph[N_LIMIT];
vector<int> inverce_graph[N_LIMIT];
int node_group[N_LIMIT];
unordered_map<int, bool> group_graph[N_LIMIT];
int input_sides[N_LIMIT];
int output_sides[N_LIMIT];
vector<int> stack;
vector<int> one_group;
int actual_group = 1;
int nodes;
int sides;
int a, b;

void add_new_side(int a, int b){
    graph[a].push_back(b);
    inverce_graph[b].push_back(a);
}

void load_data(){
    cin >> nodes;
    cin >> sides;
    int i = sides;
    while(i--){
        cin >> a >> b;
        add_new_side(a, b);
    }
}

void DFS_first(int node){
    visited[node] = true;
    for(auto child:graph[node]){
        if(!visited[child]){
            DFS_first(child);
        }
    }
    stack.push_back(node);
}

void DFS_second(int node){
    visited[node] = true;
    one_group.push_back(node);
    for(auto child:inverce_graph[node]){
        if(!visited[child]){
            DFS_second(child);
        }
    }
}

void Kosaraju_algorithm(){
    for(int i = 1; i <= nodes; i++){
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
            one_group.clear();
            DFS_second(actual_node);
            for(auto node:one_group){
                node_group[node] = actual_group;
            }
            actual_group++;
        }
    }
}

void make_group_graph(){
    for(int i = 1; i <= nodes; i++){
        for(auto child:graph[i]){
            if(node_group[i] != node_group[child]){
                group_graph[node_group[i]][node_group[child]]  = true;
                output_sides[node_group[i]]++;
                input_sides[node_group[child]]++;
            }
        }
    }
}

void make_result(){

    if(actual_group == 2){
        cout << 0 << endl;
        return;
    }

    int not_output_sides = 0;
    int not_input_sides = 0;
    for(int i = 1; i < actual_group; i++){
        if(!input_sides[i]){
            not_input_sides++;
        }
        if(!output_sides[i]){
            not_output_sides++;
        }
    }
    cout << max(not_input_sides, not_output_sides);
}

int main(){
    load_data();
    Kosaraju_algorithm();
    make_group_graph();
    make_result();
}