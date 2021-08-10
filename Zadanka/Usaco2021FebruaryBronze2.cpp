#include<iostream>
#include<vector>

using namespace std;

int const x_limit = 1e3+3;
int matrix_of_neighbours[x_limit][x_limit];
bool matrix_of_cows[x_limit][x_limit];
int N;
int a, b;
int actual_confortable_cows;
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void add_new_cow(){
    cin >> a >> b;
    a++;  b++;
    matrix_of_cows[a][b] = true;
    if(matrix_of_neighbours[a][b] == 3){
        actual_confortable_cows++;
    }
    for(auto move:moves){
        matrix_of_neighbours[a + move.first][b + move.second]++;
        if(matrix_of_neighbours[a + move.first][b + move.second] == 3 && matrix_of_cows[a + move.first][b + move.second]){
            actual_confortable_cows++;
        }
        else if(matrix_of_neighbours[a + move.first][b + move.second] == 4 && matrix_of_cows[a + move.first][b + move.second]){
            actual_confortable_cows--;
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
        cout << actual_confortable_cows << endl;
    }
}