#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;

int n;
map<int, vector<int>> numbers_indexes;
vector<int> numbers;
int min_number = INT_MAX;
int max_number = INT_MIN;
int new_number;
vector<int> primary_numbers;
map<int, vector<int>> graph;
vector<int> Q, Q2;
int const M = 1e6+2;
bool visited[M];

void load_data(){
    cin >> n;
    numbers.push_back(0);
    for(int i = 1; i <= n; i++){
        cin >> new_number;
        min_number = min(min_number, new_number);
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
        for(int i = min_number; i <= max_number/primary_number; i++){
            graph[i].push_back(i*primary_number);
            graph[i*primary_number].push_back(i);
        }
    }
}

void find_result(){
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
        int number = numbers[i];
        Q.clear();
        for(auto child:graph[number]){
            Q.push_back(child);
        }
        for(int j = 1; j <= max_number; j++){
            visited[j]=false;
        }
        visited[number] = true;
        vector<int>possible_results;
        while(possible_results.empty()){
            Q2.clear();
            for(auto item:Q){
                visited[item] = true;
                if(!numbers_indexes[item].empty()){
                    possible_results.push_back(item);
                }
                else if(possible_results.empty()){
                    for(auto child:graph[item]){
                        if(!visited[child]){
                            Q2.push_back(child);
                        }
                    }
                }
            }
            Q = Q2;
        }

        int min_index = INT_MAX;
        for(auto possible_result:possible_results){
            min_index = min(min_index, numbers_indexes[possible_result][0]);
        }
        cout << min_index << endl;
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