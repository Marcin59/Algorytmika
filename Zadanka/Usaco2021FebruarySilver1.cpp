#include<iostream>
#include<vector>

using namespace std;

int const x_limit = 1e3*3;
int matrix_of_neighbours[x_limit][x_limit];
bool matrix_of_cows[x_limit][x_limit];
bool matrix_of_adding_cows[x_limit][x_limit];
int N;
int a, b;
int needed_cows;
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void add_new_needed_cow(int k, int l){
    needed_cows++;
    for(auto move:moves){
        if(!matrix_of_cows[k + move.first][l + move.second]){
            matrix_of_cows[k + move.first][l + move.second] = true;
            matrix_of_adding_cows[k + move.first][l + move.second] = true;
            for(auto move2:moves){
                matrix_of_neighbours[k + move.first + move2.first][l + move.second + move2.second]++;
            }
            if(matrix_of_neighbours[k + move.first][l + move.second] == 3){
                add_new_needed_cow(k + move.first, l + move.second);
            }
            for(auto move2:moves){
                if(matrix_of_neighbours[k + move.first + move2.first][l + move.second + move2.second] == 3 && matrix_of_cows[k + move.first + move2.first][l + move.second + move2.second]){
                    add_new_needed_cow(k + move.first + move2.first, l + move.second + move2.second);
                }
            }
            return;
        }
    }
}

void add_new_cow(){
    cin >> a >> b;
    a += 1000;
    b += 1000;
    matrix_of_cows[a][b] = true;
    if(matrix_of_adding_cows[a][b]){
        matrix_of_adding_cows[a][b] = false;
        needed_cows--;
        return;
    }
    for(auto move:moves){
        matrix_of_neighbours[a + move.first][b + move.second]++;
    }
    if(matrix_of_neighbours[a][b] == 3){
        add_new_needed_cow(a, b);
    }
    for(auto move:moves){
        if(matrix_of_neighbours[a + move.first][b + move.second] == 3 && matrix_of_cows[a + move.first][b + move.second]){
            add_new_needed_cow(a + move.first, b + move.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    while(N--){
        add_new_cow();
        cout << needed_cows << endl;
    }
}
