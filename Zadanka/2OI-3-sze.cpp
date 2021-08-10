#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
float n;
float a, b;
vector<vector<float>> activities;

bool the_key(const vector<float>& activity1, const vector<float>& activity2){
    return activity1[0]*activity2[1] >activity2[0]*activity1[1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(float i = 1; i <= n; i++){
        cin >> a >> b;
        activities.push_back({a, b, i});
    }
    sort(activities.begin(), activities.end(), the_key);
    for(auto item:activities){
        cout << item[2] << endl;
    }
}