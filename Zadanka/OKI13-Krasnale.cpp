#include<iostream>

using namespace std;
int n, m;
int a, b;
unsigned long long result = 1;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        if(a != b){
            result /= 2;
        }
    }
    cout << result;
}