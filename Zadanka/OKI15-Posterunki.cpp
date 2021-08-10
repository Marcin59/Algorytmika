#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>

using namespace std;

map<int, bool> visited;
map<int, vector<int>> graph;
map<int, vector<int>> inverce_graph;
vector<int> stack;
vector<int> one_group;
vector<long long> prices;
int nodes;
int new_price;
int sides;
int a, b;
long long number_of_possibilities = 1;
long long minimum_price;
pair<long long, int> minimum_price_in_group;

void add_new_side(int a, int b){
    graph[a].push_back(b);
    inverce_graph[b].push_back(a);
}

void load_data(){
    cin >> nodes;
    prices.push_back(0);
    int i = nodes;
    while(i--){
        cin >> new_price;
        prices.push_back(new_price);
    }
    cin >> sides;
    i = sides;
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
            minimum_price_in_group = {INT_MAX, 0};
            for(auto node:one_group){
                if(minimum_price_in_group.first > prices[node]){
                    minimum_price_in_group = {prices[node], 1};
                }
                else if(minimum_price_in_group.first == prices[node]){
                    minimum_price_in_group.second++;
                }
            }
            minimum_price += minimum_price_in_group.first;
            minimum_price %= (long long)1e9+7;
            number_of_possibilities *= minimum_price_in_group.second;
            number_of_possibilities %= (long long)1e9+7;
        }
    }
}


int main(){
    load_data();
    Kosaraju_algorithm();
    cout << minimum_price << ' ' << number_of_possibilities;
}