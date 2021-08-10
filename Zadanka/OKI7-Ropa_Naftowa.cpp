#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;
vector<pair<int , int>> barrels;
int n, w;
int v, c;
double result = 0;

bool sorted_key(const pair<int , int>a, const pair<int , int>b){
    return ((double)a.first/a.second) > ((double)b.first/b.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> w;
    while(n--){
        cin >> v >> c;
        barrels.emplace_back(v, c);
    }
    sort(barrels.begin(), barrels.end(), sorted_key);
    for(auto item:barrels){
        if(w > item.second){
            result += item.first;
            w -= item.second;
        }
        else{
            result += (double)item.first*(double)w/item.second;
            break;
        }
    }
    cout << fixed << setprecision(4) << result;
}
