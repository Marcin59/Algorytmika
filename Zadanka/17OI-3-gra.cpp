#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> cards;
vector<int> result;
int new_card;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int k = n;
    while(k--){
        cin >> new_card;
        cards.push_back(new_card);
    }

    sort(cards.begin(), cards.end());

    result.push_back(cards[0]);

    for(int i = 1; i < n; i++){
        result.push_back(max(result.back(), cards[i] - result.back()));
    }
    cout << result.back();
}