#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const M = 1e5+7;
vector<int> graph[M];
int visited[M];
int n, m;
int index = 0;
int city1, city2;
bool cycle = true;
int results[M];
int begin_cycle, end_cycle;

void DFS(int node, int parent){
    visited[node] = index;
    for(int child:graph[node]){
        if(child != parent){
            if(visited[child] == index){
                begin_cycle = node;
                end_cycle = child;
                cycle = true;
            }
            else{
                results[child] = node;
                DFS(child, node);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    while(m--){
        cin >> city1 >> city2;
        graph[city1].push_back(city2);
        graph[city2].push_back(city1);
    }
    for(int i = 1; i <= n; i++){
        if(results[i] == 0){
            cycle = false;
            index++;
            DFS(i, i);
            if(!cycle){
                cout << "NIE";
                return 0;
            }
            else {
                for (int k = 0; k < graph[begin_cycle].size(); k++) {
                    if (graph[begin_cycle][k] == end_cycle){
                        swap(graph[begin_cycle][k], graph[begin_cycle].back());
                    }
                }
                for (int k = 0; k < graph[end_cycle].size(); k++) {
                    if (graph[end_cycle][k] == begin_cycle){
                        swap(graph[end_cycle][k], graph[end_cycle].back());
                    }
                }
                graph[begin_cycle].pop_back();
                graph[end_cycle].pop_back();
                index++;
                results[begin_cycle] = end_cycle;
                DFS(begin_cycle, begin_cycle);
            }
        }
    }
    cout << "TAK" << endl;
    for(int i = 1;i <= n; i++){
        cout << results[i] << endl;
    }
}