#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
unordered_map<int, vector<int>> numbers_in_original_word;
int n, m;
int new_number;
int lenght_new_number;
int actual_index;
int p;
int start, center, the_end;

int first_k_after_i_index(int k, int i){
    if(numbers_in_original_word[k].empty()){
        return 0;
    }
    start = 0;
    the_end = (int)numbers_in_original_word[k].size()-1;
    while(the_end > start){
        center = (start+the_end)/2;
        if(numbers_in_original_word[k][center] <= i) start = center+1;
        else the_end = center;
    }
    return numbers_in_original_word[k][start];
}

void answer_the_question(){
    actual_index = 0;
    cin >> lenght_new_number;
    while(lenght_new_number--){
        cin >> new_number;
        p = first_k_after_i_index(new_number, actual_index);
        if(p > actual_index){
            actual_index = p;
        }
        else{
            cout << "NIE" << endl;
            for(int i = lenght_new_number; i > 0; i--){
                cin >> new_number;
            }
            return;
        }
    }
    cout << "TAK" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> new_number;
        numbers_in_original_word[new_number].push_back(i);
    }
    cin >> m;
    while(m--){
        answer_the_question();
    }
}