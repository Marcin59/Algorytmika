#include<iostream>
#include<vector>

using namespace std;

int n, m;
int const M = 2e5+5;
int visited[M];
int index= 0;
vector<int> graph[M];
int city1, city2;
vector<char> results;

void DFS(int node, int parent){
    visited[node] = index;
    for(int child:graph[node]){
        if(child != parent){
            if(visited[child] != index){
                if(results[node] == 'K'){
                    results[child] = 'S';
                }
                else{
                    results[child] = 'K';
                }
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
    results.assign(M, 'N');
    while(m--){
        cin >> city1 >> city2;
        graph[city1].push_back(city2);
        graph[city2].push_back(city1);
    }
    for(int i = 1; i <= n; i++){
        if (graph[i].empty()){
            cout << "NIE" << endl;
            return 0;
        }
        if(results[i] == 'N'){
            ++index;
            results[i] = 'K';
            DFS(i, i);
        }
    }
    cout << "TAK" << endl;
    for(int i = 1; i <= n; i++){
        cout << results[i] << endl;
    }
}
