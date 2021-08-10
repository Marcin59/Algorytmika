#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>

using namespace std;

int const N_LIMIT = 1e2+2;

vector<pair<int,int>> graph[N_LIMIT];
int results[N_LIMIT][N_LIMIT];
int n, q;
int node, weight;

int number_of_connections;

void load_data(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> number_of_connections;
        for (int j = 0; j < number_of_connections; ++j) {
            cin >> node >> weight;
            graph[i].push_back({node, weight});
        }
    }
}

void find_result(){
    queue<int> Q;
    int actual_node;
    for (int i = 1; i <= n; ++i) {
        for(auto item: results[i]){
            item = INT_MIN;
        }
        results[i][i] = INT_MAX;
        for(auto item: graph[i]){
            Q.push(item.first);
            results[i][item.first] = item.second;
        }
        while(!Q.empty()){
            actual_node = Q.front();
            Q.pop();
            for(auto child:graph[actual_node]){
                if(results[i][child.first] < min(results[i][actual_node], child.second)){
                    results[i][child.first] = min(results[i][actual_node], child.second);
                    Q.push(child.first);
                }
            }
        }

    }
}

void print_result(){
    cin >> q;
    int from, to;
    for (int i = 0; i < q; ++i) {
        cin >> from >> to;
        cout << results[from][to] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_result();
    print_result();
}