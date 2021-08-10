#include<iostream>

using namespace std;
const int M = 3e5+3;
int holes[M];
int actual_puck;
int n, m;
int actual_hol;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    cin >> actual_hol;
    holes[1] = actual_hol;
    for(int i = 2; i <= n; i++){
        cin >> actual_hol;
        holes[i] = min(actual_hol, holes[i-1]);
    }
    int i = n;
    while(m--){
        cin >> actual_puck;
        while(holes[i] < actual_puck){
            i--;
            if(i==0){
                cout << 0;
                return 0;
            }
        }
        holes[i] = 0;
    }
    cout << i;
}
