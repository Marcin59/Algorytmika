#include<iostream>
#include<map>

using namespace std;
int n;
int a, b;
map<int, int> input_sides;

void load_data(){
    cin >> n;
    while(--n){
        cin >> a >> b;
        input_sides[a]++;
        input_sides[b]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}