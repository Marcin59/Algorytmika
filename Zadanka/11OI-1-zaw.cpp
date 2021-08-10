#include<iostream>
#include<climits>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

int const N_LIMIT = 5e3+3;
int const M_LIMIT = 1e4+3;
int n, m;
int a, b, c, d;
map<int, map<int, int>> graph;
queue<int> the_queue;
pair<int, int> fastest_way[N_LIMIT];
pair<int, int> fastest_inverce_way[N_LIMIT];

void load_data(){
    cin >> n >> m;
    int i = m;
    while(i--){
        cin >> a >> b >> c >> d;
        graph[a][b] = c;
        graph[b][a ]= d;
    }
}

void djiskra(){
    for(int i = 0; i < N_LIMIT; i++){
        fastest_way[i].first = INT_MAX;
        fastest_inverce_way[i].first = INT_MAX;
    }
    fastest_way[1].first = 0;
    fastest_inverce_way[1].first = 0;
    fastest_way[1].second = 1;
    fastest_inverce_way[1].second = 1;

    for(auto child:graph[1]){
        fastest_way[child.first].first = child.second;
        fastest_way[child.first].second = child.first;
        fastest_inverce_way[child.first].first = graph[child.first][1];
        fastest_inverce_way[child.first].second = child.first;
        the_queue.push(child.first);
    }

    int data;
    int node, weight;
    while(!the_queue.empty()){
        data = the_queue.front();
        the_queue.pop();

        for(auto child:graph[data]){

            node = child.first;
            weight =child.second;
            if(fastest_way[data].first + weight < fastest_way[node].first){
                fastest_way[node].first = fastest_way[data].first + weight;
                fastest_way[node].second = fastest_way[data].second;
                the_queue.push(node);
            }
        }
    }

    for(auto child:graph[1]){
        the_queue.push(child.first);
    }
    while(!the_queue.empty()){
        data = the_queue.front();
        the_queue.pop();

        for(auto child:graph[data]){

            node = child.first;
            weight = graph[node][data];
            if(fastest_inverce_way[data].first + weight < fastest_inverce_way[node].first){
                fastest_inverce_way[node].first = fastest_inverce_way[data].first + weight;
                fastest_inverce_way[node].second = fastest_inverce_way[data].second;
                the_queue.push(node);
            }
        }
    }
    int result = INT_MAX;
    for(int i = 2; i <= n; i++){
        for(auto child:graph[i]){
            if(fastest_way[i].second != fastest_inverce_way[child.first].second && child.first != 1) {
                result = min(result, fastest_way[i].first + child.second + fastest_inverce_way[child.first].first);
            }
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
}