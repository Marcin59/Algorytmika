#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;
int const N_LIMIT = 1e5+2;
int n;
int the_time, a, new_input_node;
vector<int> activities_times;
map<int, vector<int>> graph;
map<int, vector<int>> inverce_graph;
vector<int> nodes_in_topologic_sort;
queue<int> the_queue;
vector<int> input_nodes;
int max_to[N_LIMIT];
int max_from[N_LIMIT];
long long max_path;
int questions;

void load_data(){
    cin >> n;
    activities_times.push_back(0);
    input_nodes.push_back(0);
    for(int i = 1; i <= n; i++){
        cin >> the_time;
        activities_times.push_back(the_time);
        cin >> a;
        input_nodes.push_back(a);
        while(a--){
            cin >> new_input_node;
            graph[i].push_back(new_input_node);
            inverce_graph[new_input_node].push_back(i);
        }
    }
//    cout << "Graph:" << endl;
//    for(auto node:graph){
//        cout << "Node: " << node.first << endl;
//        cout << "Child: ";
//        for(auto child:node.second){
//            cout << child << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;
}

void topologic_sort(){
    for(int i = 1; i <= input_nodes.size()-1; i++){
        if(input_nodes[i] == 0){
            the_queue.push(i);
        }
    }
    int actual_node;
    while(!the_queue.empty()){
        actual_node = the_queue.front();
        nodes_in_topologic_sort.push_back(actual_node);
        the_queue.pop();
        for(auto child:inverce_graph[actual_node]){
            input_nodes[child]--;
            if(input_nodes[child] == 0){
                the_queue.push(child);
            }
        }
    }
//    cout << "Nodes_int_topologic_sort:" << endl;
//    for(auto node:nodes_in_topologic_sort){
//        cout << node << " ";
//    }
//    cout << endl << endl;
}

void find_max_path(){
    max_path = 0;
    for(auto node:nodes_in_topologic_sort){
        max_to[node] = 0;
        for(auto v:graph[node]){
            max_to[node] = max(max_to[node], max_to[v]);
        }
        max_to[node] += activities_times[node];
        max_path = max(max_path, (long long)max_to[node]);
    }
    for(int i = nodes_in_topologic_sort.size()-1; i >= 0; i--){
        int node = nodes_in_topologic_sort[i];
        max_from[node] = 0;
        for(auto v:inverce_graph[node]){
            max_from[node] = max(max_from[node], max_from[v]+activities_times[v]);
        }
    }

//    cout << "Max_to:" << endl;
//    for(int i = 1; i <= n; i++){
//        cout << i << ": "  << max_to[i] << endl;
//    }
//    cout << endl;
}

void answer_questions(){
    cout << max_path << endl;
    cin >> questions;
    int v, d;
    while(questions--){
        cin >> v >> d;
        if(d > max_path - max_to[v] - max_from[v]){
            cout << "TAK" << endl;
        }
        else{
            cout << "NIE" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    topologic_sort();
    if(nodes_in_topologic_sort.size() == n){
        find_max_path();
        answer_questions();
    }
    else{
        cout << "CYKL" << endl << endl;
    }
}