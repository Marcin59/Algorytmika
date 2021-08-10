#include<iostream>
#include<map>

using namespace std;
map<char, pair<int, int>> moves;
int n;
char new_move;
int surface;

void answer_the_question(){
    surface = 0;
    pair<int, int> vector1;
    pair<int, int> vector2;
    cin >> new_move;
    vector1 = moves[new_move];
    vector2 = moves[new_move];
    cin >> new_move;
    vector2.first += moves[new_move].first;
    vector2.second += moves[new_move].second;
    while(vector2.first != 0 || vector2.second != 0 ){
        surface += vector1.first*vector2.second - vector1.second*vector2.first;
        cin >> new_move;
        vector1 = vector2;
        vector2.first += moves[new_move].first;
        vector2.second += moves[new_move].second;
    }
    if(surface < 0){
        cout << "CW" << endl;
    }
    else{
        cout << "CCW" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    moves['S'] = {0, -1};
    moves['N'] = {0, 1};
    moves['W'] = {-1, 0};
    moves['E'] = {1, 0};
    cin >> n;
    while(n--){
        answer_the_question();
    }
}