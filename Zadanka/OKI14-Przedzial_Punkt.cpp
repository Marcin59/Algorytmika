#include<iostream>

using namespace std;

int const M = 1<<17;
long long tree[M<<1];
int n, actual_command;
long long modulo = 1e9+7;

void update(long long a, long long b, long long c){
    a += M-1;
    b += M+1;
    while(b/2 != a/2){
        if(a%2 == 0)  tree[a+1] = (tree[a+1] * c) % modulo;
        if(b%2 == 1) tree[b-1] = (tree[b-1] * c) % modulo;
        a /= 2; b /= 2;
    }
}

long long query(int index){
    index += M;
    long long res = 1;
    while(index){
        res =  res * tree[index] % modulo;
        index /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(long long & i : tree){
        i = 1;
    }
    cin >> n;
    while(n--){
        cin >> actual_command;
        if(actual_command == 0){
            long long a, b, c;
            cin >> a >> b >> c;
            update(a, b, c);
        }
        else{
            int index;
            cin >> index;
            cout << query(index) << endl;
        }
    }
}