#include<iostream>
#include<vector>

using namespace std;
const int M = 1e5+2;
int input_sides[M];
vector<pair<int, int>> tunels;
int n, m, k;
int a, b;
int number_of_sets = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    tunels.emplace_back(0, 0);
    int x = m;
    while(x--){
        cin >> a >> b;
        input_sides[a]++;
        input_sides[b]++;
        tunels.emplace_back(a, b);
    }
    for(int i = 1; i<= m; i++){
        a = tunels[i].first;
        b = tunels[i].second;
        input_sides[a]--;
        input_sides[b]--;

    }
}