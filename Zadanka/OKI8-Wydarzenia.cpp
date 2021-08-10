#include<iostream>
#include<set>

using namespace std;
int const M = 1e6+3;
int parents[M];
int deph[M];
set<int, greater<>> hearing_story;
int n, m;
int x;

int parent(int a){
    if(parents[a] != a){
        return parent(parents[a]);
    }
    else{
        return a;
    }
}

void connect(int a, int b){
    int parent1 = parent(a);
    int parent2 = parent(b);
    if(parent2 == 0) return;
    if(parent1 == parent2) return;
    if(deph[parent1] < deph[parent2]){
        int prev = parent1;
        parent1 = parent2;
        parent2 = prev;
    }
    parents[parent2] = parent1;
    if(deph[parent1] == deph[parent2]){
        deph[parent1]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        parents[i] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> x;
        connect(i, x);
    }
    cin >> m;
    while(m--){
        cin >> x;
        hearing_story.insert(parent(x));
    }
    cout << hearing_story.size();
}