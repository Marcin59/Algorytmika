#include<iostream>
#include<vector>
#include<map>

using namespace std;

const int M = 5e2+2;
map<int, vector<int>> graph;
vector<int> commanders;
bool visited[M];
int commands[M];
vector<int> result;
int n, m, k;

void load_data(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m;
        if(!m){
            commanders.push_back(i);
            commands[i] = 2;
        }
        while(m--){
            cin >> k;
            graph[k].push_back(i);
        }
    }
}

void DFS(int node){
    for(auto child:graph[node]){
        if(commands[child] < 2 && !visited[child]){
            visited[child] = true;
            commands[child]++;
            DFS(child);
        }
    }
}

void make_result(){
    for(auto command:commanders){
        for(auto &item:visited){
            item = false;
        }
        DFS(command);
    }
    for(int i = 1; i <= n; i++){
        if(commands[i] != 2){
            result.push_back(i);
        }
    }
}

void print_result(){
    if(result.empty()){
        cout << "BRAK";
    }
    for(auto item:result){
        cout << item << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_result();
    print_result();
}