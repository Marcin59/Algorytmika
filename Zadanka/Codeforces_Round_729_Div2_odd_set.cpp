#include<iostream>
#include<vector>

using namespace std;

int number_of_questions;
int actual_question_lenght;
int even_numbers;
int new_elem;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> number_of_questions;
    for (int i = 0; i < number_of_questions; ++i) {
        cin >> actual_question_lenght;
        even_numbers = 0;
        for (int j = 0; j < actual_question_lenght*2; ++j) {
            cin >> new_elem;
            if (new_elem%2){
                even_numbers++;
            }
        }
        if (even_numbers == actual_question_lenght) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}