#include<iostream>

using namespace std;

int n;
int x, y;
int a, b;
pair<long long, long long> vector1, vector2;
long long result = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> x >> y;
    cin >> a >> b;
    vector1 = {a - x, b - y};
    for(int i = 2; i < n; i++){
        vector2 = vector1;
        cin >> a >> b;
        vector1 = {a - x, b - y};
        result += (long long)vector1.first*vector2.second-vector1.second*vector2.first;
    }
    cout << (long long)abs(result)/2;
    if(result%2){
        cout << ".5";
    }
}