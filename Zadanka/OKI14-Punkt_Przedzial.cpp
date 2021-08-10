#include<iostream>
#include<climits>

using namespace std;

int const M = 1<<17;
int tree[M<<1];
int n, actual_command;

void update(int index, int value){
    index += M-1;
    tree[index] = value;
    index /= 2;
    while(index) {
        tree[index] = max(tree[index*2], tree[index*2+1]);
        index /= 2;
    }
}

int query(int a, int b){
    int max_value = -INT_MAX;
    a += M-2;
    b += M;
    while(b/2 != a/2){
        if(a%2 == 0) max_value = max(max_value, tree[a+1]);
        if(b%2 == 1) max_value = max(max_value, tree[b-1]);
        a /= 2; b /= 2;
    }
    return max_value;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--){
        cin >> actual_command;
        if(actual_command == 0){
            int index, value;
            cin >> index >> value;
            update(index, value);
        }
        else{
            int a, b;
            cin >> a >> b;
            cout << query(a, b) << endl;
        }
    }
}