#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long a, b, cuts_number, n;
vector<long long> x_cuts, y_cuts;
long long x = 0, y = 0;
long long new_elem;

long long cnt(long long k){
    long long result = 0;
    long long i = 0;
    long long j = cuts_number;
    while(i<=cuts_number && j>= 0){
        if(x_cuts[i]*y_cuts[j] >= k){
            result += cuts_number+1-i;
            j--;
        }
        else i++;
    }
    return result;
}

long long binary_search_result(){
    long long p, k, s;
    p = x_cuts[0]*y_cuts[0];
    k = x_cuts.back()*y_cuts.back();
    while(p < k) {
        s = (p + k + 1) >> 1;
        if (cnt(s) < n) k = s - 1;
        else p = s;
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b >> cuts_number >> n;
    for(int i = 0; i < cuts_number; i++){
        cin >> new_elem;
        x_cuts.push_back(new_elem-x);
        x = new_elem;
    }
    x_cuts.push_back(a-x);
    for(int i = 0; i < cuts_number; i++){
        cin >> new_elem;
        y_cuts.push_back(new_elem - y);
        y = new_elem;
    }
    y_cuts.push_back(b - y);
    sort(x_cuts.begin(), x_cuts.end());
    sort(y_cuts.begin(), y_cuts.end());
    cout << binary_search_result();
}