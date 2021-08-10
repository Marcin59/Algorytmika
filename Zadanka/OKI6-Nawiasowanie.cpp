#include<iostream>
#include<string>

using namespace std;
int open_brukets_number;
string word;
int result = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> word;
    for(char letter:word){
        if(letter == '('){
            open_brukets_number++;
        }
        else if(!open_brukets_number){
            result++;
        }
        else{
            open_brukets_number--;
        }
    }
    result += open_brukets_number;
    cout << result;
}