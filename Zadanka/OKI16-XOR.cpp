#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const N_LIMIT = 1e5+2;
int n, m, k;
int a, b;
vector<pair<pair<int, int>, int>> questions;
int numbers[N_LIMIT];
int results[N_LIMIT];
int actual_result = 0;
int actual_start = 0;
int actual_end = 0;

bool key(pair<pair<int, int>, int> item1, pair<pair<int, int>, int> item2){
    if(item1.first.first != item2.first.first) return (item1.first.first < item2.first.first);
    return (item1.first.second < item2.first.second);
}

void load_data(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> numbers[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        questions.push_back({{a, b}, i});
    }
}

void count_actual_result_from_zero(int start, int end){
    actual_result = 0;
    actual_start = start;
    actual_end = end;
    int actual_xor;
    for(int i = start; i <= end; i++){
        actual_xor = 0;
        for(int j = i; j <= end; j++){
            actual_xor ^= numbers[j];
            if(actual_xor == k){
                actual_result++;
            }
        }
    }
}

void remove_from_start(){
    int actual_xor = 0;
    for(int i = actual_start; i <= actual_end; i++){
        actual_xor ^= numbers[i];
        if(actual_xor == k){
            actual_result--;
        }
    }
    actual_start++;
}

void add_to_end(){
    int actual_xor = 0;
    actual_end++;
    for(int i = actual_end; i >= actual_start; i--){
        actual_xor ^= numbers[i];
        if(actual_xor == k){
            actual_result++;
        }
    }
}

void remove_from_end(){
    int actual_xor = 0;
    for(int i = actual_end; i >= actual_start; i--){
        actual_xor ^= numbers[i];
        if(actual_xor == k){
            actual_result--;
        }
    }
    actual_end--;
}

void find_results(){
    sort(questions.begin(), questions.end(), key);
    for(auto &question:questions){
        if(question.first.first > actual_end){
            count_actual_result_from_zero(question.first.first, question.first.second);
            results[question.second] = actual_result;
        }
        else{
            while(actual_start < question.first.first){
                remove_from_start();
            }
            while(actual_end < question.first.second){
                add_to_end();
            }
            while(actual_end > question.first.second){
                remove_from_end();
            }
            results[question.second] = actual_result;
        }
    }
}

void print_result(){
    for(int i = 1; i <= m; i++){
        cout << results[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_results();
    print_result();
}