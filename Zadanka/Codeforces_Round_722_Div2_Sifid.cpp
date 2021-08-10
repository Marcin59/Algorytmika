#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

int number_of_questions;
int number_of_elems_actual_question;
vector<int> actual_question;
int new_elem;

void load_new_array(){
    actual_question.clear();
    cin >> number_of_elems_actual_question;
    for (int i = 0; i < number_of_elems_actual_question; ++i) {
        cin >> new_elem;
        actual_question.push_back(new_elem);
    }
}

int find_result(){
    sort(actual_question.begin(), actual_question.end());
    if(actual_question[0] > 0) return 1;
    int minimum_number_differce = INT_MAX;
    for (int i = 1; i < number_of_elems_actual_question; ++i) {
        if(actual_question[i] - actual_question[i-1] < minimum_number_differce){
            minimum_number_differce = actual_question[i] - actual_question[i-1];
        }
        if(actual_question[i] > 0){
            if(actual_question[i] > minimum_number_differce) return i;
            return i + 1;
        }
    }
    return number_of_elems_actual_question;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> number_of_questions;
    for (int i = 0; i < number_of_questions; ++i) {
        load_new_array();
        cout << find_result() << endl;
    }
}