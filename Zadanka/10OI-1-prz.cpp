#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<climits>

using namespace std;


int const M = 5e3+3;
int metals_number;
int metals_costs[M];
int new_cost;
int actions_number;
map<int, map<int, int>> graph;
map<int, map<int, int>> inverce_graph;
int a, b, weight;
int fastest_way[M];
int fastest_inverce_way[M];
queue<int> the_queue;

void load_data(){
    cin >> metals_number;
    for(int i = 1;  i <= metals_number; i++){
        cin >> new_cost;
        metals_costs[i] = new_cost;
    }
    cin >> actions_number;
    while(actions_number--){
        cin >> a >> b >> weight;
        graph[a][b] = weight;
        inverce_graph[b][a] = weight;
    }
}

void djiskra(){
    for(int i = 0; i < M; i++){
        fastest_way[i] = INT_MAX;
        fastest_inverce_way[i] = INT_MAX;
    }
    fastest_way[1] = 0;
    the_queue.push(1);

    int node;
    int child_node, child_weight;
    while(!the_queue.empty()){
        node = the_queue.front();
        the_queue.pop();
        for(auto child:graph[node]){
            child_node = child.first;
            child_weight = child.second;
            if(fastest_way[child_node] > fastest_way[node] + child_weight){
                fastest_way[child_node] = fastest_way[node] + child_weight;
                the_queue.push(child_node);
            }
        }
    }

    fastest_inverce_way[1] = 0;
    the_queue.push(1);

    while(!the_queue.empty()){
        node = the_queue.front();
        the_queue.pop();
        for(auto child:inverce_graph[node]){
            child_node = child.first;
            child_weight = child.second;
            if(fastest_inverce_way[child_node] > fastest_inverce_way[node] + child_weight){
                fastest_inverce_way[child_node] = fastest_inverce_way[node] + child_weight;
                the_queue.push(child_node);
            }
        }
    }
}

void print_result(){
    int result = INT_MAX;
    for(int i = 1; i <= metals_number; i++){
        if(metals_costs[i] / 2 + fastest_way[i] + fastest_inverce_way[i]>0){
            result = min(result, metals_costs[i] / 2 + fastest_way[i] + fastest_inverce_way[i]);
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    djiskra();
    print_result();
}