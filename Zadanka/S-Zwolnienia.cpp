#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int n;
int minimum_strong_team;
vector<int> individual_strong;
long long actual_sum = 0;
vector<long long> sums;
int new_individual_strong;
int result = 0;
map<int, bool> must_be;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> minimum_strong_team;
    individual_strong.push_back(new_individual_strong);
    while(n--){
        cin >> new_individual_strong;
        individual_strong.push_back(new_individual_strong);
    }
    sort(individual_strong.begin(), individual_strong.end());

    for(auto strong:individual_strong){
        actual_sum += strong;
        sums.push_back(actual_sum);
    }

    int end = 1;
    for(int start = 1; start < individual_strong.size(); start++){
        while(end+1 < individual_strong.size() && sums[end] - sums[start-1] < minimum_strong_team){
            end++;
        }
        must_be[end] = true;
        int k = 0;
        for(int i = end; k < minimum_strong_team; i--){
            k += sums[i]-sums[i-1];
            must_be[i] = true;
        }

        if(sums[end] - sums[start] >= minimum_strong_team && !must_be[start]){
            result++;
        }
    }
    if(sums.back() >= minimum_strong_team){
        cout << result;
    }
    else{
        cout << individual_strong.size()-1;
    }
}
