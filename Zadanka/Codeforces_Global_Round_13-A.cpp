#include<iostream>

using namespace std;

int const N_limit = 1e5+4;
int n, m;
int elements[N_limit];
int count_1;
int count_0;
int a, b;

void load_data(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> elements[i];
        if(elements[i] == 1){
            count_1++;
        } else{
            count_0++;
        }
    }
    while(m--){
        cin >> a >> b;
        if(a == 1){
            if(elements[b] == 1){
                elements[b] = 0;
                count_0++;
                count_1--;
            }
            else{
                elements[b] = 1;
                count_0--;
                count_1++;
            }
        }
        else{
            if(b <= count_1){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}
