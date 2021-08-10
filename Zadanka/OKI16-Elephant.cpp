#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

const int N_LIMIT = 1e5+4;
int elements_number, questions;
int new_elem;
int a, b;
vector<int> interesting_elemnts;
int elements[N_LIMIT];
unordered_map<int, int> number_of_appearances;
vector<int> prefix_appearances[N_LIMIT];

void load_data(){
    cin >> elements_number >> questions;
    for(int i = 1; i <= elements_number; i++){
        cin >> new_elem;
        number_of_appearances[new_elem]++;
        elements[i] = new_elem;
    }
}

void find_interesting_elements(){
    for(auto elem:number_of_appearances){
        if(elem.first <= elem.second){
            interesting_elemnts.push_back(elem.first);
        }
    }
}

void make_prefix_appearances(){
    int actual_appearances;
    for(auto interesting_element:interesting_elemnts){
        actual_appearances = 0;
        for(auto elem:elements){
            if(elem == interesting_element){
                actual_appearances++;
            }
            prefix_appearances[interesting_element].push_back(actual_appearances);
            if(actual_appearances == number_of_appearances[interesting_element]){
                break;
            }
        }
    }
}

void answer_questions(){
    int result;
    int start, end;
    while(questions--){
        cin >> a >> b;
        result = 0;
        for(auto interesting_element:interesting_elemnts){
            if(b >= prefix_appearances[interesting_element].size()){
                end = prefix_appearances[interesting_element].back();
            }
            else{
                end = prefix_appearances[interesting_element][b];
            }

            if(a-1 >= prefix_appearances[interesting_element].size()){
                start = prefix_appearances[interesting_element].back();
            }
            else{
                start = prefix_appearances[interesting_element][a-1];
            }
            if(end - start == interesting_element){
                result++;
            }
        }
        cout << result << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_interesting_elements();
    make_prefix_appearances();
    answer_questions();
}