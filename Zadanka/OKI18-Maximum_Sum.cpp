#include<iostream>

using namespace std;
int questions;
int x;
const int X_LIMIT = 16;
int matrix[X_LIMIT+1][X_LIMIT+1];
int dp[X_LIMIT+1][X_LIMIT+1];
int new_elem;

void answer_the_question(){
    cin >> x;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= x; j++){
            cin >> new_elem;
            matrix[i][j] = new_elem;
        }
    }

    dp[1][1] = matrix[1][1];
    for(int i = 2; i <= x; i++){
        dp[1][i] = max(dp[1][i-1], dp[1][i-2]+matrix[1][i]);
        dp[i][1] = max(dp[i-1][1], dp[i-2][1]+matrix[i][1]);
    }
    for(int i = 2; i <= x; i++){
        for(int j = 2; j <= x; j++){
            dp[i][j] = max(dp[i-1][j] + dp[i][j-1] - dp [i-1][j-1], dp[i-2][j] + dp[i][j-2] - dp [i-2][j-2] + matrix[i][j]);
        }
    }

//    for(int i = 1; i <= x; i++){
//        for(int j = 1; j <= x; j++){
//            cout << dp[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;

    cout << dp[x][x] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> questions;
    while(questions--){
        answer_the_question();
    }
}