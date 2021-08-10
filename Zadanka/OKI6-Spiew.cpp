#include<iostream>

using namespace std;
int n;
char actual_state;
int result;
int repeat_number = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--){
        cin >> actual_state;
        if(actual_state == 'Z'){
            repeat_number++;
            if(repeat_number == 3){
                result++;
                repeat_number = 0;
            }
        }
        else{
            if(repeat_number){
                result++;
                repeat_number = 0;
            }
        }
    }
    if(repeat_number){
        result++;
    }
    cout << result;
}