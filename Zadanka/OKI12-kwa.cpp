#include<iostream>
#include<map>

using namespace std;

long long const M = 1e5+4;
int result = 0;
long long a, x, n;
map<int, bool> visited;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> x >> n;
    while(!visited[x]){
        result++;
        visited[x] = true;
        x = (x*x+a) % n;
    }
    cout << result << endl;
}