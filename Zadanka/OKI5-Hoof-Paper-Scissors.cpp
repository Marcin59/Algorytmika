#include<iostream>

using namespace std;

int const N_LIMIT = 1e5;
int const K_LIMIT = 20;

int n, k;
char new_move;
int moves[N_LIMIT];
int dp[N_LIMIT+1][K_LIMIT+1][3];

void load_data(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> new_move;
        if(new_move == 'H') moves[i] = 0;
        if(new_move == 'P') moves[i] = 1;
        if(new_move == 'S') moves[i] = 2;
    }
}

void make_dp(){
    int another_state1;
    int another_state2;
    for(int i = 0 ; i <= n; i++){
        for(int j = 0; j <= k; j++){
            for(int state = 0; state < 3; state++){
                if(i == 0){
                    dp[i][j][state] = 0;
                }
                else if(j == 0){
                    dp[i][j][state] = dp[i-1][j][state] + (moves[i-1] == state ? 1 : 0);
                }
                else{
                    another_state1 = (state + 1)%3;
                    another_state2 = (state + 2)%3;
                    dp[i][j][state] = max(max(dp[i-1][j][state], dp[i-1][j-1][another_state1]), dp[i-1][j-1][another_state2]) + (moves[i-1] == state ? 1 : 0);
                }
            }
        }
    }
    cout << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_dp();
}