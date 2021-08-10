#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

long long n, p, d;
long long new_pit;
vector<int> pits;
const int base = 1<<21;
long long possible_board[base<<1];
vector<long long> sums;
long long result = 0;

void load_data(){
    cin >> n >> p >> d;
    pits.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> new_pit;
        pits.push_back(new_pit);
    }
}

void update(long long index, long long value){
    index += base-1;
    possible_board[index] = value;
    index /= 2;
    while(index){
        possible_board[index] = max(possible_board[index*2], possible_board[index*2+1]);
        index /= 2;
    }
}

long long query(long long a, long long b){
    long long max_value = INT_MIN;
    a += base-2;
    b += base;
    while(b/2 != a/2){
        if(a%2 == 0) max_value = max(max_value, possible_board[a+1]);
        if(b%2 == 1) max_value = max(max_value, possible_board[b-1]);
        a /= 2; b /= 2;
    }
    return max_value;
}

void make_tree() {

    long long actual_sum = 0;
    sums.push_back(actual_sum);
    for (int i = 1; i <= n ; i++) {
        actual_sum += pits[i];
        sums.push_back(actual_sum);
    }
    for (int i = d; i <= n; i++) {
        update(i - d + 1, sums[i] - sums[i-d]);
    }
//    for (int i = 1; i <= n - d + 1; i++) {
//        cout << i << "==>" << i + d - 1 << " : " << possible_board[i + base - 1] << endl;
//    }
}

void find_result(){
    result = d;
    long long end =  d;

    for(int i = 1; i <= n-d+1; i++){
        end = max(end, i+d-1);
        while(end < n && (sums[end+1]-sums[i-1]) - query(i, end-d+2) <= p){
            end++;
        }
//        cout << "start: " << i << "  end: " << end << endl;
//        cout << "actual_sum: " << (sums[end]-sums[i-1]) << endl;
        result = max(result, end-i+1);
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_tree();
    find_result();
}