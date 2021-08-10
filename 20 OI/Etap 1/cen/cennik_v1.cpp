#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

int const N_LIMIT = 1e5 + 3;

using namespace std;
long long n, m, k, a, b;
vector<int> graph[N_LIMIT];
int fastest_way[N_LIMIT];
bool visited[N_LIMIT];
int first_node, second_node;

int main(){
    cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < m; ++i) {
        cin >> first_node >> second_node;
        graph[first_node].push_back(second_node);
        graph[second_node].push_back(first_node);
    }

    queue<int> Q;
    visited[k] = true;
    for(int i =  0; i < graph[k].size(); i++){
        Q.push(graph[k][i]);
        visited[graph[k][i]] = true;
        fastest_way[graph[k][i]] = 1;
    }
    while (!Q.empty()){
        int actual_node;
        actual_node = Q.front();
        Q.pop();
        for(auto child:graph[actual_node]){
            if(!visited[child]){
                fastest_way[child] = fastest_way[actual_node] + 1;
                visited[child] = true;
                Q.push(child);
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        long long cheapest_with_BLL = (fastest_way[i]/2)*b;
        if(fastest_way[i] % 2 == 1){
            cheapest_with_BLL += a;
        }
        cout << min(cheapest_with_BLL, fastest_way[i]*a) << endl;
    }
}