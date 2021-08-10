#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<sstream>
#include <cmath>

using namespace std;

int const N_LIMIT = 144+1;
int const MIN_degrees = 15;
int const MAX_degrees = 34;
int const DIF_degrees = 20;

struct degree{
    int cost;
    int last_move;
    bool possible;
};

int n;
vector<vector<int>> moves;
vector<int> actual_moves;
degree degrees[N_LIMIT][DIF_degrees];

void reset_degrees_matrix(){

    for (int i = 0; i < N_LIMIT; ++i) {
        for (int j = 0; j < DIF_degrees; ++j) {
            degrees[i][j].possible = false;
        }
    }
}

void find_and_print_result(){
    int minimum_value = INT_MAX;
    int minimum_value_index = -1;
    vector<int> result;
    for (int i = 0; i < DIF_degrees; ++i) {
        if(degrees[n][i].possible){
            if(minimum_value > degrees[n][i].cost){
                minimum_value = degrees[n][i].cost;
                minimum_value_index = i;
            }
        }
    }
    if(minimum_value_index == -1){
        cout << "NIE" << endl;
    }
    else{
        int index = minimum_value_index;
        for (int i = n; i > 0 ; --i) {
            result.push_back(degrees[i][index].last_move);
            index -= degrees[i][index].last_move;
        }
        for (int i = n-1; i >= 0 ; --i) {
            cout << result[i] << ' ';
        }
        cout << endl;
    }
}

void load_data(){
    cin >> n;
    string s;
    getline( cin, s );
    for (int i = 1; i <= n; ++i) {
        actual_moves.clear();
        getline( cin, s );
        stringstream text_stream(s);
        string s1;
        while (getline(text_stream, s1, ' ')) {
            actual_moves.push_back(stoi(s1));
        }
        moves.push_back(actual_moves);
    }
}

void find_result(){
    for (int i = 0; i < DIF_degrees; ++i) {
        degrees[0][i].possible = true;
        for (int j = 1; j <= n; ++j) {
            for(auto degrees_change:moves[j-1]){
                for (int k = max(0, degrees_change); k < min(DIF_degrees, DIF_degrees + degrees_change); ++k) {
                    if(degrees[j-1][k-degrees_change].possible){
                        if(!degrees[j][k].possible || degrees[j][k].cost > degrees[j-1][k-degrees_change].cost + abs(degrees_change)){
                            degrees[j][k].possible = true;
                            degrees[j][k].last_move = degrees_change;
                            degrees[j][k].cost = degrees[j-1][k-degrees_change].cost + abs(degrees_change);
                        }
                    }
                }
            }
        }
        find_and_print_result();
        reset_degrees_matrix();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_result();
}