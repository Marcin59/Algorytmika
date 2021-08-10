#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<queue>

using namespace std;

int n;
map<int, vector<int>> numbers_indexes;
vector<int> numbers;
int max_number = INT_MIN;
int new_number;
vector<int> primary_numbers;
map<int, vector<int>> graph;
queue<int> Q;
int const M = 1e6+2;
int results[M];
int results_ms[M];

void load_data(){
    cin >> n;
    numbers.push_back(0);
    for(int i = 1; i <= n; i++){
        cin >> new_number;
        max_number = max(max_number, new_number);
        numbers_indexes[new_number].push_back(i);
        numbers.push_back(new_number);
    }
}

void find_primary_numbers_below_k(int k){
    bool all_numbers[k+1];
    for(int i = 2; i <= k; i++){
        all_numbers[i] = true;
    }
    for(int i = 2; i*i<= k; i++){
        if(all_numbers[i]){
            for(int j = i*2; j <= k; j += i) {
                all_numbers[j] = false;
            }
        }
    }
    for(int i = 2; i <= k; i++){
        if(all_numbers[i]){
            primary_numbers.push_back(i);
        }
    }
}

void make_graph(){
    for(int primary_number:primary_numbers){
        for(int i = 1; i <= max_number/primary_number; i++){
            graph[i].push_back(i*primary_number);
            graph[i*primary_number].push_back(i);
        }
    }
}

void find_result(){

    int ds[max_number+1];
    int ms[max_number+1];

    for(auto &item:graph){
        ds[item.first] = INT_MAX;
    }

    for(const auto& item:numbers_indexes){
        ds[item.first] = 0;
        ms[item.first] = item.first;
        Q.push(item.first);
    }

    int v;
    while(!Q.empty()){
        v = Q.front();
        Q.pop();
        for(auto child:graph[v]){
            if(ds[child] == INT_MAX){
                ds[child] = ds[v]+1;
                ms[child] = ms[v];
                Q.push(child);
            }
            else if(ds[v]+1 == ds[child] && numbers_indexes[ms[v]] < numbers_indexes[ms[child]]){
                ms[child] = ms[v];
            }
        }
    }

    for(const auto& item:numbers_indexes){
        results[item.first] = INT_MAX;
    }

    int w;
    int d;
    for(int i = 1; i <= max_number; i++){
        for(auto node:graph[i]){
            v = ms[i];
            w = ms[node];
            if(v != w){
                d = ds[i] + 1 + ds[node];
                if(d < results[v] || (d == results[v] && numbers_indexes[w] < numbers_indexes[results_ms[v]])){
                    results[v] = d;
                    results_ms[v] = w;
                }
            }
        }
    }

    for(int i = 1; i < numbers.size(); i++){
        if(numbers_indexes[numbers[i]].size() > 1){
            if(i == numbers_indexes[numbers[i]][0]){
                cout << numbers_indexes[numbers[i]][1] << endl;
            }
            else{
                cout << numbers_indexes[numbers[i]][0] << endl;
            }
            continue;
        }
        cout << numbers_indexes[results_ms[numbers[i]]][0] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
//    for(auto item:numbers_indexes){
//        cout << item.first << " " << item.second << endl;
//    }
//    cout << "max_number: " << max_number << endl;
//    cout << "min_number: " << min_number << endl;
    find_primary_numbers_below_k(max_number);
//    cout << "primary_numbers: ";
//    for(auto item:primary_numbers){
//        cout << item << ' ';
//    }
//    cout << endl;
    make_graph();
//    for(const auto& node:graph){
//        cout << "node: " << node.first << endl;
//        cout << "childs: ";
//        for(auto child: node.second){
//            cout << child << ' ';
//        }
//        cout << endl;
//    }
    find_result();
}