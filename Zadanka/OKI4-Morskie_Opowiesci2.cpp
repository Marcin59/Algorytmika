#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int const N_LIMIT = 5e3+2;
int fastest_way[N_LIMIT][N_LIMIT];
vector<int> graph[N_LIMIT];
int n, m, k;
int a, b;
int s, t, d;
deque<int> Q;
int actual_visited_number = 1;

void load_data(){
    cin >> n >> m >> k;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b+n);
        graph[b].push_back(a+n);
        graph[a+n].push_back(b);
        graph[b+n].push_back(a);
    }
}

void BFS(int start_node){
    int actual_distance = 0;
    Q.push_back(start_node);
    int l;
    int actual_node;
    if(graph[start_node].empty()){
        return;
    }
    while(!Q.empty()){
        l = Q.size();
        for(int i = 0; i < l; i++){
            actual_node = Q.front();
            Q.pop_front();
            fastest_way[start_node][actual_node] = actual_distance;
            for(auto child:graph[actual_node]){
                if(fastest_way[start_node][child] == -1){
                    Q.push_back(child);
                }
            }
        }
        actual_distance++;
    }
}

void make_fastest_way(){
    for(auto &i:fastest_way){
        for(int &j:i){
            j = -1;
        }
    }
    for(int i = 1; i <= n; i++){
        BFS(i);
        actual_visited_number++;
    }
}

void answer_the_questions(){
    while(k--){
        cin >> s >> t >> d;
//        cout << "Fastest way from: " << s << " to: " << t << " ==> " << fastest_way[s][t] << endl;
        if(fastest_way[s][t] != -1 && fastest_way[s][t] <= d && !((d - fastest_way[s][t])%2)){
            cout << "TAK" << endl;
        }
        else if(fastest_way[s][t+n] != -1 && fastest_way[s][t+n] <= d && !((d - fastest_way[s][t+n])%2)){
            cout << "TAK" << endl;
        }
        else{
            cout << "NIE" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_fastest_way();
    answer_the_questions();
}