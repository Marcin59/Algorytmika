#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
const int M = 5e4+3;
bool visited[M];
vector<int> D;
vector<int> S;
int new_elem;
int x, j, y;
vector<int> result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    n *= 2;
    while(n--){
        cin >> new_elem;
        S.push_back(new_elem);
    }
    reverse(S.begin(), S.end());
    while(!S.empty()){
        x = S.back();
        S.pop_back();
        if(!visited[x]){
            D.push_back(x);
            visited[x] = true;
        }
        else{
            j = (int)D.size();
            y = D.back();
            D.pop_back();
            visited[y] = false;
            if(x != y){
                result.push_back(j);
                S.push_back(y);
                S.push_back(x);
            }
        }
    }
    cout << result.size() << endl;
    for(auto item:result){
        cout << item << endl;
    }
}
