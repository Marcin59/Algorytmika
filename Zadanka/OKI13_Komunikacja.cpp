#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<int, int> communicators;
string new_com;
int n, k;
long long result;

void load_data(){
    cin >> n >> k;
    while(n--){
        cin >> new_com;
        communicators[stoi(new_com, nullptr, 2)]++;
    }
}

void find_result(){
    for(auto item1:communicators){
        for(auto item2:communicators){
            if(item1.first & item2.first){
                if(item1.first != item2.first){
                    result += (long long)item1.second * item2.second;
                }
                else if(item1.second > 1){
                    result += (long long)item1.second * (item1.second - 1);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_result();
    cout << result/2;
}