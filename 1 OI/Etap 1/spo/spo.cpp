#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int number_of_times;
vector<double> times;
vector<int> dp;
double new_time;
int result = 0;

void load_data(){
    cin >> number_of_times;
    dp.push_back(0);
    times.push_back(0);
    for (int i = 0; i < number_of_times; ++i) {
        cin >> new_time;
        times.push_back(new_time);
        dp.push_back(1);
    }
}

void find_result(){
    for (int i = 1; i <= number_of_times; ++i) {
        for (int j = 1; j < i; ++j) {
            if (times[i] < times[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        result = max(result, dp[i]);
    }
}

void print_result(){
    cout << result*100;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_result();
    print_result();
}