#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
int a, b;
vector<pair<int ,int>> intervals;
int start, over;

bool the_key(pair<int ,int> interval1, pair<int ,int> interval2){
    return interval1.first < interval2.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--){
        cin >> a >> b;
        intervals.emplace_back(a, b);
    }
    sort(intervals.begin(), intervals.end(), the_key);
    start = intervals[0].first;
    over = intervals[0].second;
    for(auto interval:intervals){
        if(interval.first > over){
            cout << start << ' ' << over << endl;
            start = interval.first;
            over = interval.second;
        }
        else{
            over = max(interval.second, over);
        }
    }
    cout << start << ' ' << over << endl;
}