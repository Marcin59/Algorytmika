#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

int const N_LIMIT = 1e5+4;
int n, m;
int a, b, c;
vector<pair<int, int>> graph[N_LIMIT]; // child node, distance
pair<long long, vector<int>> fastest_way[N_LIMIT];
bool result[N_LIMIT];

void load_data(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        if(a == b) continue;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
}

void djiskra(){
    for(auto &item:fastest_way){
        item.first = LONG_LONG_MAX;
    }
    queue<int> Q;
    Q.push(1);
    fastest_way[1].first = 0;
    int actual_node;
    while(!Q.empty()){
        actual_node = Q.front();
        Q.pop();
        for(auto child:graph[actual_node]){
            if(fastest_way[child.first].first > fastest_way[actual_node].first + child.second){
                fastest_way[child.first].first = fastest_way[actual_node].first + child.second;
                fastest_way[child.first].second.clear();
                fastest_way[child.first].second.push_back(actual_node);
                Q.push(child.first);
            }
            else if(fastest_way[child.first].first == fastest_way[actual_node].first + child.second){
                fastest_way[child.first].second.push_back(actual_node);
            }
        }
    }
}

void dfs(int actual_node){
    result[actual_node] = true;
    for(auto child:fastest_way[actual_node].second){
        dfs(child);
    }
}

void find_and_print_result(){
    dfs(n);
    for(int i = 1; i <= n; i++){
        if(result[i]){
            cout << i << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    djiskra();
    find_and_print_result();
}