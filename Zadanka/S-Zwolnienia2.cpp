#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int n;
int minimum_strong_team;
vector<int> individual_strong;
int new_individual_strong;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> minimum_strong_team;
    individual_strong.push_back(new_individual_strong);
    while (n--) {
        cin >> new_individual_strong;
        if (new_individual_strong < minimum_strong_team) {
            individual_strong.push_back(new_individual_strong);
        }
    }
    sort(individual_strong.begin(), individual_strong.end());

    int result = individual_strong.size()-1;
    int k = 0;
    for(int i = 1; i<individual_strong.size()-1; i++){
        if(individual_strong[i] + individual_strong.back() >= minimum_strong_team){
            k++;
        }
    }
    if(k == 0){
        cout << result;
    }
    else{
        cout << result-k-1;
    }
}
