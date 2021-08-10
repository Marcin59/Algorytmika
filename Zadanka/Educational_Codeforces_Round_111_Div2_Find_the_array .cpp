#include<iostream>

using namespace std;

int number_of_questions;
int actual_question;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> number_of_questions;
    for (int i = 0; i < number_of_questions; ++i) {
        cin >> actual_question;
        int n = 1;
        int answer = 0;
        while(actual_question >= n){
            actual_question -= n;
            n += 2;
            answer++;
        }
        if(actual_question != 0){
            answer++;
        }
        cout << answer << endl;
    }
}
