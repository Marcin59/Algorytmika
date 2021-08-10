#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long n;
int prime_numbers[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 31, 37, 41};
vector<pair<int, int>> candidates;
vector<pair<int, int>> acepted_candidates;

void generate_all_candidates(int j, int max_pow, int cand, int divider_number){
    candidates.emplace_back(cand, divider_number);
    for(int i = 1; i <= max_pow; i++){
        if(prime_numbers[j] > n/cand) return;
        cand = cand * prime_numbers[j];
        generate_all_candidates(j+1, i, cand, divider_number*(i+1));
    }
}

bool key(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    generate_all_candidates(1, 31, 1, 1);
    sort(candidates.begin(), candidates.end(), key);
    int max_number_of_divines = 0;
    for(auto item:candidates){
        if(item.second > max_number_of_divines){
            max_number_of_divines = item.second;
            acepted_candidates.emplace_back(item);
        }
    }
    cout << acepted_candidates.back().first;
}