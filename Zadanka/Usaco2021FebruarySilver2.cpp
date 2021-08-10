#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, k;
vector<pair<int, int>> elements_intervals;
int result;
vector<int> breaks;
int new_elem;

void load_data(){
    cin >> n >> k;
    k--;
    while(n--){
        cin >> new_elem;
        elements_intervals.emplace_back(12*(new_elem/12)+12, 12*(new_elem/12));
    }
    elements_intervals.emplace_back(0, 0);
    sort(elements_intervals.begin(), elements_intervals.end(), greater<>());
//    for(auto item:elements_intervals){
//        cout << item.first << ' ' << item.second << endl;
//    }
//    cout << endl;
    result = elements_intervals.front().first;
    for(int i = 1; i <= elements_intervals.size()-1; i ++){
        if(elements_intervals[i].first < elements_intervals[i-1].second){
            breaks.push_back(elements_intervals[i-1].second - elements_intervals[i].first);
        }
    }
    sort(breaks.begin(), breaks.end(), greater<>());
//    for(auto item : breaks){
//        cout << item << ' ';
//    }
//    cout << endl << endl;
    for(int i = 0; i < k; i++){
        if(i >= breaks.size()){
            break;;
        }
        result -= breaks[i];
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}