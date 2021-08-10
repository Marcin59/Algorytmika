#include<iostream>
#include<climits>

using namespace std;

int const N_LIMIT = 2e5+3;

int n;
int positions[N_LIMIT];
int distances[N_LIMIT];
int dist;
int new_elem;
int result = INT_MIN;

void load_data(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> new_elem;
        positions[new_elem] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> new_elem;
        dist = positions[new_elem] - i;
        if(dist < 0){
            dist += n;
        }
        distances[dist]++;
    }
    for(int i = 0; i < n; i++){
        result = max(result, distances[i]);
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}