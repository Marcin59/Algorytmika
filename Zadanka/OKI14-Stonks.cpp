#include<iostream>

using namespace std;

const int N_LIMIT = 2e5+2;
int n, q, x;
int elements[N_LIMIT];
long long sums[N_LIMIT];
long long mins[N_LIMIT];
long long maxs[N_LIMIT];
int a, b;

void update_result(){
    cin >> a >> b;
    elements[a] = b - x;
    for(int i = a; i <= n; i++){
        sums[i] = sums[i-1]+elements[i];
        mins[i] = min(mins[i-1], sums[i]);
        maxs[i] = max(maxs[i-1], sums[i] - mins[i]);
    }
    cout << maxs[n] << ' ';
}

void load_data(){
    cin >> n >> q >> x;
    for(int i = 1; i <= n; i++){
        cin >> elements[i];
        elements[i] -= x;
        sums[i] = sums[i-1]+elements[i];
        mins[i] = min(mins[i-1], sums[i]);
        maxs[i] = max(maxs[i-1], sums[i] - mins[i]);
    }
    cout << maxs[n] << ' ';
    while(q--){
        update_result();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}