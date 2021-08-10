#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int number_of_times;
vector<float> times;
vector<float> dp;
float new_time;

void load_data(){
    cin >> number_of_times;
    times.push_back(0);
    for (int i = 0; i < number_of_times; ++i) {
        cin >> new_time;
        times.push_back(new_time);
    }
}

void find_result(){
    dp.push_back(31);
    for (int i = 1; i <= number_of_times; ++i) {
        int n = dp.size()-1;
        if (times[i] < dp[n]){
            dp.push_back(times[i]);
        };
        n--;
        for (int j = n; j >= 0; j--) {
            if (times[i] < dp[j]){
                if (times[i] > dp[j+1]){
                    dp[j+1] = times[i];
                }
            }
        }
    }
}

void print_result(){
    cout << (dp.size()-1)*100;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_result();
    print_result();
}