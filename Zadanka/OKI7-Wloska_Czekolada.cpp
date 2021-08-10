#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int M = 1e6+4;
int n;
int starts[M];
int the_ends[M];
vector<pair<int, int>> intervals;// <start, end>
map<int, bool> visited;
int result;
int new_elem;

bool the_key(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> new_elem;
        visited[new_elem] = true;
        if(starts[new_elem] != 0){
            the_ends[new_elem] = i;
        }
        else{
            starts[new_elem] = i;
            the_ends[new_elem] = i;
        }
    }
    for(auto [key, value]:visited){
        intervals.emplace_back(starts[key], the_ends[key]);
    }
    sort(intervals.begin(), intervals.end(), the_key);

    int actual_time = 0;
    for(auto item:intervals){
        if(item.first >= actual_time){
            actual_time = item.second;
            result++;
        }
    }
    cout << result;
}