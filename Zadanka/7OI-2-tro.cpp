#include<iostream>
#include<vector>

using namespace std;
const int M = 4e5;
int p, q, n;
bool busy[M];
int i;
vector<vector<int>> result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> p >> q >> n;
    if(q < p){
        int h = q;
        q = p;
        p = h;
    }
    i = 1;
    while(i <= n){
        if(busy[i]){
            i++;
            continue;
        }
        if(busy[i+p]){
            int h = q;
            q = p;
            p = h;
        }
        result.push_back({i, i+p, i+p+q});
        busy[i] = true;
        busy[i+p] = true;
        busy[i+p+q] = true;
    }
    cout << result.size() << endl;
    for(auto & j : result){
        cout << j[0] << ' ' << j[1] << ' ' << j[2] << endl;
    }
}