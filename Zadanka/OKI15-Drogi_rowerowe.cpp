#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
#include<queue>

using namespace std;

const int N_LIMIT = 5e4 + 4;
map<int, bool> visited;
map<int, vector<int>> graph;
map<int, vector<int>> inverce_graph;
queue<int> the_queue;
vector<int> nodes_in_topologic_sort;
map<int, int> number_input_sides;
vector<int> stack;
vector<int> one_group;
int numbers_of_groups[N_LIMIT];
int actual_group_number = 1;
map<int, int> group_size;
map<int, int> possible_visited_of_group;
map<int, map<int, bool>> groups_graph;
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
                numbers_of_groups[node] = actual_group_number;
                group_size[actual_group_number]++;
            }
            possible_visited_of_group[actual_group_number] += one_group.size();
            actual_group_number++;
        }
    }
}

void make_groups_graph(){
    for(const auto& parent:inverce_graph){
        for(auto child:parent.second){
            if(numbers_of_groups[parent.first] != numbers_of_groups[child]){
                if(!groups_graph[numbers_of_groups[parent.first]][numbers_of_groups[child]]){
                    groups_graph[numbers_of_groups[parent.first]][numbers_of_groups[child]] = true;
                    number_input_sides[numbers_of_groups[child]]++;
                }
            }
        }
    }
}

void topologic_sort(){
    for(int i = 1; i < actual_group_number; i++){
        if(!number_input_sides[i]){
            the_queue.push(i);
        }
    }
    int actual_element;
    while(!the_queue.empty()){
        actual_element = the_queue.front();
        nodes_in_topologic_sort.push_back(actual_element);
        the_queue.pop();
        for(auto child : groups_graph[actual_element]){
            number_input_sides[child.first]--;
            if(!number_input_sides[child.first]){
                the_queue.push(child.first);
            }
        }
    }
}

void make_possible_visited_group_faster(){
    for(auto node:nodes_in_topologic_sort){
        for(auto child:groups_graph[node]){
            if(child.second) {
                possible_visited_of_group[child.first] += possible_visited_of_group[node];
            }
        }
    }
}

void print_answer(){
    for(int i = 1; i <= nodes; i++){
        cout << possible_visited_of_group[numbers_of_groups[i]]-1 << endl;
    }
}

int main(){
    load_data();
    Kosaraju_algorithm();
    make_groups_graph();
    topologic_sort();
    make_possible_visited_group_faster();
    print_answer();
//
//    cout << endl << "Groups in tologic sort:" << endl;
//    for(auto group:nodes_in_topologic_sort){
//        cout << group << ' ';
//    }
//    cout << endl;
}