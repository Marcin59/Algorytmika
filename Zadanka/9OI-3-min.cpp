#include<iostream>

using namespace std;
char the_minus;
char actual_char;
char last_char;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> actual_char;
    the_minus = actual_char;
    last_char = actual_char;
    cout << the_minus;
    n -= 2;
    while(n--){
        cin >> actual_char;
        if(actual_char != last_char){
            if(actual_char == the_minus){
                cout << ')';
            }
            else{
                cout << '(';
            }
        }
        cout << the_minus;
        last_char = actual_char;
    }
    if(actual_char != the_minus){
        cout << ')';
    }
}