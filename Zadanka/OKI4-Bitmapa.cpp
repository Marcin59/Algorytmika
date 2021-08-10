#include<iostream>
#include<string>
#include<vector>
#include<array>

using namespace std;
int const M = 190;
int n, m;
string pixels_board[M];
vector<short int> results[M];
vector<array<short int, 2>> Q;

void print_results(){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

void find_minimum_ways(){
    int k = 1;
    short int new_value;
    while(not Q.empty()){
        int l = Q.size();
        for(int i = 0; i < l; i++){
            auto data = Q.back();
            Q.pop_back();
            if(data[0] > 0 && results[data[0]-1][data[1]] == -1){
                new_value = data[0]-1;
                Q.insert(Q.begin(), {new_value, data[1]});
                results[new_value][data[1]] = k;
            }
            if(data[1] > 0 && results[data[0]][data[1]-1] == -1){
                new_value = data[1]-1;
                Q.insert(Q.begin(), {data[0], new_value});
                results[data[0]][new_value] = k;
            }
            if(data[0] < n-1 && results[data[0]+1][data[1]] == -1){
                new_value = data[0]+1;
                Q.insert(Q.begin(), {new_value, data[1]});
                results[new_value][data[1]] = k;
            }
            if(data[1] < m-1 && results[data[0]][data[1]+1] == -1){
                new_value = data[1]+1;
                Q.insert(Q.begin(), {data[0], new_value});
                results[data[0]][new_value] = k;
            }
        }
        k++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        results[i].assign(M, -1);
    }
    for(int i = 0; i < n; i++){
        cin >> pixels_board[i];
    }
    for(short int i = 0; i < n; i++){
        for(short int j = 0; j < m; j++){
            if(pixels_board[i][j] == '1'){
                Q.push_back({i, j});
                results[i][j] = 0;
            }
        }
    }
    find_minimum_ways();
    print_results();
}