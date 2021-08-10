#include<iostream>

using namespace std;

int const RESULT_MAX = 18;
int n, m;
int number_of_appearances[RESULT_MAX+1][1 << RESULT_MAX];
int possibilities[RESULT_MAX];
string lamps;
int actual_change;

void print_result(){
    for(int i = 1; i <= RESULT_MAX; i++){
        if(possibilities[i] != (1 << i)){
            cout << i << endl;
            break;
        }
    }
}

void load_data(){
    cin >> n >> m;
    cin >> lamps;
    int mask_substring;
    for(int i = 1; i < RESULT_MAX; i ++){
        for(int j = 0; j+i <= n; j++){
            mask_substring = stoi(lamps.substr(j, i), nullptr, 2);
            number_of_appearances[i][mask_substring]++;
            if(number_of_appearances[i][mask_substring] == 1){
                possibilities[i]++;
            }
        }
    }
}

void change_state(){
    int mask_substring;
    for(int i = 1; i < RESULT_MAX; i++){
        for(int j = max(0, actual_change-i); j+i <= min(n, actual_change + i); j++){
            mask_substring = stoi(lamps.substr(j, i), nullptr, 2);
            number_of_appearances[i][mask_substring]--;
            if(number_of_appearances[i][mask_substring] == 0){
                possibilities[i]--;
            }
        }
    }
    if(lamps[actual_change] == '1'){
        lamps[actual_change] = '0';
    }
    else lamps[actual_change] = '1';
    for(int i = 1; i < RESULT_MAX; i++){
        for(int j = max(0, actual_change-i); j+i <= min(n, actual_change + i); j++){
            mask_substring = stoi(lamps.substr(j, i), nullptr, 2);
            number_of_appearances[i][mask_substring]++;
            if(number_of_appearances[i][mask_substring] == 1){
                possibilities[i]++;
            }
        }
    }
}

void answer_the_questions(){
    print_result();
    while(m--){
        cin >> actual_change;
        actual_change--;
        change_state();
        print_result();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    answer_the_questions();
}