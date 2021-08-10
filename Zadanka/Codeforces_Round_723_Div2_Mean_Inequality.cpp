#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int number_of_questions;
int number_of_array_elements;
vector<int> actual_array;
int new_elem;

void answer_the_question(){
    actual_array.clear();
    cin >> number_of_array_elements;
    number_of_array_elements *= 2;
    for (int i = 0; i < number_of_array_elements; ++i) {
        cin >> new_elem;
        actual_array.push_back(new_elem);
    }
    sort(actual_array.begin(), actual_array.end());
    for (int i = 0; i < number_of_array_elements/2; i++) {
        cout << actual_array[i] << ' ';
        cout << actual_array[number_of_array_elements - i - 1] << ' ';
    }
    cout << '\n';
}

int main(){
    cin >> number_of_questions;
    for (int i = 0; i < number_of_questions; ++i) {
        answer_the_question();
    }
}