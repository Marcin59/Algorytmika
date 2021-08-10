#include<iostream>

using namespace std;
int n;
int new_elem;
const int M = 5e5+5;
int array[M];
int max_value = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> new_elem;
        array[i] = new_elem;
        if(new_elem >= max_value){
            cout << -1 << endl;
            max_value = new_elem;
        }
        else{
            for(int j = i-1; j > 0; j--){
                if(array[j] > new_elem){
                    cout << j << endl;
                    break;
                }
            }
        }
    }
}