#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

int const N_LIMIT = (1e5 + 3)*2;

using namespace std;
int n, m, k, a, b;
vector<int> graph[N_LIMIT];
bool visited[N_LIMIT];
int fastest_way[N_LIMIT];
int first_node, second_node;

int main(){
    cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < m; ++i) {
        cin >> first_node >> second_node;
        graph[first_node].push_back(second_node+n);
        graph[second_node].push_back(first_node+n);
        graph[first_node+n].push_back(second_node);
        graph[second_node+n].push_back(first_node);
    }

    queue<int> Q;
    visited[k] = true;
    visited[k+n] = true;
    for(auto child: graph[k]){
        fastest_way[child] = 1;
        Q.push(child);
        visited[child] = true;
    }

    while(!Q.empty()){
        int actual_node = Q.front();
        Q.pop();
        for(auto child: graph[actual_node]){
            if(!visited[child]){
//                if(child <= n){
//                    if(fastest_way[actual_node] == fastest_way[child+n]){
//                        continue;
//                    }
//                }
                visited[child] = true;
                fastest_way[child] = fastest_way[actual_node] + 1;
                Q.push(child);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << fastest_way[i] << endl;
    }

    cout << endl;

    for(int i = n+1; i <= n*2; i++){
        cout << fastest_way[i] << endl;
    }

    cout << endl;

    for(int i = 1; i <= n; i++){
        if(i == k){
            cout << 0 << endl;
            continue;
        }
        if(fastest_way[i] == 0){
            cout << min(fastest_way[i+n]*a, fastest_way[i+n]/2*b + a) << endl;
        }
        else if (fastest_way[i+n] == 0){
            cout << min(fastest_way[i]*a, fastest_way[i]/2*b) << endl;
        }
        else{
            cout << min(min(fastest_way[i+n]*a, fastest_way[i+n]/2*b + a), min(fastest_way[i]*a, fastest_way[i]/2*b)) << endl;
        }
    }
}