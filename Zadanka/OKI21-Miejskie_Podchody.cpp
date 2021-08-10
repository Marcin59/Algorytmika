#include<iostream>
#include<vector>
#include<deque>
#include<climits>
#include<algorithm>

using namespace std;

int const unm_limit = 1e6+4;
int u, n, m;
vector<int> start_people_positions;
bool start[unm_limit];
bool the_double;
vector<pair<int, int>> graph[unm_limit]; // node, distance
pair<long long, int> distances[unm_limit];
int new_people_position;
int a, b, c;

struct elem_in_queue{
    int actual_node;
    int start_position;
    long long distance;
};

void load_data(){
    cin >> u >> n >> m;
    for(int i = 1; i <= u; i++){
        cin >> new_people_position;
        if(start[new_people_position]){
            the_double = true;
        }
        start[new_people_position] = true;
        start_people_positions.push_back(new_people_position);
    }
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
}

void djiskra(){
    deque<elem_in_queue> Q; // node, node_parent
    for(auto &item:distances){
        item = {INT_MAX, 0};
    }
    elem_in_queue new_elem{};
    new_elem.distance = 0;
    for(auto node:start_people_positions){
        new_elem.start_position = node;
        new_elem.actual_node = node;
        Q.push_back(new_elem);
        distances[node] = {0, node};
    }

    elem_in_queue data{};
    while(!Q.empty()){
        data = Q.front();
        Q.pop_front();
        for(auto child: graph[data.actual_node]){
            if(child.first != data.start_position && distances[child.first].first > data.distance + child.second){
                distances[child.first] = {data.distance + child.second, data.start_position};
                new_elem.distance = distances[child.first].first;
                new_elem.actual_node = child.first;
                new_elem.start_position = data.start_position;
                Q.push_back(new_elem);
            }
        }
    }

    long long result = INT_MAX;
    for(int i = 0; i < n; i++){
        for(auto item:graph[i]){
            if(distances[i].second != distances[item.first].second){
                result = min(result, distances[i].first + distances[item.first].first + item.second);
            }
        }
    }
    if(the_double){
        result = 0;
    }
    cout << result*3;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    djiskra();
}