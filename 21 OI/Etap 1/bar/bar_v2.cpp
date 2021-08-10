#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const N_LIMIT = 1e6 + 3;

string fruits;
int n;
int last_seen[N_LIMIT*2];
bool seen[N_LIMIT*2];
pair<int, int> peak_point[N_LIMIT];

pair<int, int> choose_pair(pair<int, int> pair1, pair<int, int> pair2){
    if(pair1.first > pair2.first){
        return pair1;
    }
    else if (pair1.first == pair2.first){
        if(pair1.second > pair2.second){
            return pair1;
        }
        else return pair2;
    }
    else return pair2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> fruits;

    int result = 0;

    int actual_point_value = n;
    peak_point[n] = {actual_point_value, n};
    last_seen[actual_point_value] = n;
    for(int i = n-1; i >= 0; i--){
        if(fruits[i] == 'j'){
            actual_point_value++;
        }
        else{
            actual_point_value--;
        }
        pair<int, int> actual_point = {actual_point_value, i};
        peak_point[i] = actual_point;

        if(fruits[i] == 'p'){
            peak_point[i] = choose_pair(peak_point[i], peak_point[i+1]);
            if(seen[actual_point_value]){
                peak_point[i] = choose_pair(peak_point[i], peak_point[last_seen[actual_point_value]]);
            }
        }
        last_seen[actual_point_value] = i;
        seen[actual_point_value] = true;

        result = max(result, peak_point[i].second - i);
    }
//    for (int i = 0; i < n; ++i) {
//        cout << peak_point[i].first << ' ';
//    }
//    cout << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << peak_point[i].second << ' ';
//    }
//    cout << endl;

    cout << result;
}