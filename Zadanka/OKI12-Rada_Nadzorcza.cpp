#include<iostream>

using namespace std;

const int M = 360;
bool last[M];
bool actual[M];
int n, actual_move;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    actual[0] = true;
    cin >> n;
    while(n--){
        cin >> actual_move;
        for(int j = 0; j < 360; j++){
            last[j] = actual[j];
            actual[j] = false;
        }
        for(int i = 0; i < 360; i++){
            if(!last[i]) continue;
            else{
                actual[(i+actual_move)%360] = true;
                if(i-actual_move >= 0){
                    actual[i-actual_move] = true;
                }
                else{
                    actual[360 + i - actual_move] = true;
                }
            }
        }
    }
    if(actual[0]){
        cout << "TAK";
    }
    else{
        cout << "NIE";
    }
}