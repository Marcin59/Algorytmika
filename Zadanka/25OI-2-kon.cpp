#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MODULO = 1e9+7;
vector<pair<int, int>> intervals;
long long minimum_check, posibilities;
long long posibilities_base, posibilities_from_right, posibilities_from_left;
int z;
int l, n, a, b;
int the_start, the_end;

bool the_key(pair<int, int> interval1, pair<int, int> interval2){
    return interval1.first < interval2.first;
}

void answer_question(){
    intervals.clear();
    posibilities = 1;
    posibilities_base = 1;
    posibilities_from_left = 1;
    posibilities_from_right = 1;
    minimum_check = 1;
    cin >> l >> n;
    while(n--){
        cin >> a >> b;
        intervals.emplace_back(a, b);
    }
    sort(intervals.begin(), intervals.end(), the_key);
    the_start = intervals[0].first;
    the_end = intervals[0].second;
    int last_end;
    for(auto item:intervals){
        if(item.first < the_end){
            the_start = item.first;
        }
        else{
            posibilities_base *= the_end-the_start;
            the_start = item.first;
            the_end = last_end;
        }
        last_end = item.second;
    }
    posibilities_base *= last_end-the_start;

    the_start = intervals[0].first;
    the_end = intervals[0].second;
    for(auto item:intervals){
        if(item.first < the_end){
            the_start = item.first;
            the_end = min(the_end, item.second);
        }
        else{
            minimum_check++;
            posibilities_from_left *= the_end-the_start;
            the_start = item.first;
            the_end = item.second;
        }
    }
    posibilities_from_left *= the_end-the_start;

    the_start = intervals.back().second;
    the_end = intervals.back().first;
    for(int i = (int)intervals.size()-1; i >= 0; i--){
        if(intervals[i].second > the_end){
            the_start = intervals[i].second;
        }
        else{
            posibilities_from_right *= the_start - the_end;
            the_start = intervals[i].second;
            the_end = intervals[i].first;
        }
    }

    posibilities_from_right *= the_start - the_end;
    posibilities = posibilities_base + ((posibilities_from_right-posibilities_base)*(posibilities_from_left-posibilities_base));
    cout << minimum_check << ' ' << posibilities << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> z;
    while(z--){
        answer_question();
    }
}