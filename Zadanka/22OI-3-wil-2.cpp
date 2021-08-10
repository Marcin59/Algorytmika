#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

long long n, p, d;
long long new_pit;
vector<long long> pits;
deque<pair<long long, long long>> max_queue;
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

void push_queue(long long x){
    x = -x;
    long long cnt = 0;
    while(!max_queue.empty() && max_queue.back().first >= x){
        cnt += max_queue.back().second+1;
        max_queue.pop_back();
    }
    max_queue.emplace_back(x, cnt);
}
void pop_queue(){
    if(max_queue.front().second){
        max_queue.front().second--;
    }
    else{
        max_queue.pop_front();
    }
}

long long max_in_queue(){
    return - max_queue.front().first;
}

void find_result(){
    long long actual_sum = 0;
    sums.push_back(actual_sum);
    for (int i = 1; i <= n ; i++) {
        actual_sum += pits[i];
        sums.push_back(actual_sum);
    }

    result = d;
    long long end =  d;
    push_queue(sums[end]-sums[end-d]);
    push_queue(sums[end+1]-sums[end-d+1]);

    for(int i = 1; i <= n-d+1; i++){
        if(end < i+d-1){
            end = i+d-1;
            if(end < n) {
                push_queue(sums[end + 1] - sums[end - d + 1]);
            }
        }
        while(end < n && (sums[end+1]-sums[i-1]) - max_in_queue() <= p){
            end++;
            if(end < n) {
                push_queue(sums[end + 1] - sums[end - d + 1]);
            }
        }
//        cout << "start: " << i << "  end: " << end << endl;
//        cout << "actual_sum: " << (sums[end]-sums[i-1]) << endl;
//        cout << "max_int_queue: " << max_in_queue() << endl;
//        cout << endl;
        result = max(result, end-i+1);
        pop_queue();
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_result();
}