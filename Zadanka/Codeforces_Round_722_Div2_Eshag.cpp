#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int number_of_questions;
int number_of_elems_in_question;
int actual_value;
int actual_count_of_min_value;
int actual_min_value;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> number_of_questions;
    for (int i = 0; i < number_of_questions; ++i) {
        cin >> number_of_elems_in_question;
        actual_count_of_min_value = 0;
        actual_min_value = INT_MAX;
        for (int j = 0; j < number_of_elems_in_question; ++j) {
            cin >> actual_value;
            if(actual_value == actual_min_value) actual_count_of_min_value++;
            else if(actual_value < actual_min_value){
                actual_min_value = actual_value;
                actual_count_of_min_value = 1;
            }
        }
        cout << number_of_elems_in_question-actual_count_of_min_value << endl;
    }
}