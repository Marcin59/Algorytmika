#include<iostream>
#include<map>

using namespace std;
int n, t;
map<string, int> posibilities;
map<string, int> last_moves;
map<string, int> actual_moves;
string new_moves;
int result = 0;
char numbers[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void create_all_moves(){
    string new_posibility = "";
    for(auto a:numbers){
        new_posibility += a;
        for(auto b:numbers){
            if(a != b){
                new_posibility += b;
            }
            for(auto c:numbers){
                if(b != c){
                    new_posibility += c;
                }
                for(auto d:numbers){
                    if(c != d){
                        new_posibility += d;
                    }
                    cout << new_posibility << endl;
                    posibilities[new_posibility]++;
                }
            }
        }
    }
}

void create_all_moves(int k, string substring){
    if(k < 4){
        for(auto letter:numbers){
            if(letter != substring.back()){
                create_all_moves(k+1, substring+letter);
            }
            else{
                create_all_moves(k+1, substring);
            }
        }
    }
    else{
        posibilities[substring]++;
    }
}

void load_first_moves(){
    cin >> t;
    cin >> new_moves;
    for(int i = 0; i < t-3; i++){
        actual_moves[new_moves.substr(i, 4)] = true;
    }
    for(int i = 0; i < t-2; i++){
        actual_moves[new_moves.substr(i, 3)] = true;
    }
    for(int i = 0; i < t-1; i++){
        actual_moves[new_moves.substr(i, 2)] = true;
    }
    for(int i = 0; i < t; i++){
        actual_moves[new_moves.substr(i, 1)] = true;
    }
}

void load_moves(){
    last_moves = actual_moves;
    actual_moves.clear();
    cin >> t;
    cin >> new_moves;
    for(int i = 0; i < t-3; i++){
        if(last_moves[new_moves.substr(i, 4)]) {
            actual_moves[new_moves.substr(i, 4)] = true;
        }
    }
    for(int i = 0; i < t-2; i++){
        if(last_moves[new_moves.substr(i, 3)]) {
            actual_moves[new_moves.substr(i, 3)] = true;
        }
    }
    for(int i = 0; i < t-1; i++){
        if(last_moves[new_moves.substr(i, 2)]) {
            actual_moves[new_moves.substr(i, 2)] = true;
        }
    }
    for(int i = 0; i < t; i++){
        if(last_moves[new_moves.substr(i, 1)]) {
            actual_moves[new_moves.substr(i, 1)] = true;
        }
    }
}

int create_result(){
    for(const auto& item:actual_moves){
        result += posibilities[item.first];
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    create_all_moves(0, "");
    load_first_moves();
    n--;
    while(n--){
        load_moves();
    }
    cout << create_result() << endl;
}