#include<iostream>

int const K_LIMIT = 252;
using namespace std;
long long M;
int N, K;
long long possibles_sum[K_LIMIT];
pair<int, int> result; // N, K

void load_data(){
    cin >> M;
}

void make_possibles_sum(){
    int actual_possible_sum = 0;
    possibles_sum[0] = 1;
    for(int i = 1; i <= 250; i++){
        actual_possible_sum += i;
        for(int j = min(actual_possible_sum, 250); j >= i; j--){
            possibles_sum[j] += possibles_sum[j-i];
            if(possibles_sum[j] == M){
                result = {i, j};
                return;
            }
        }
    }
}

void print_possibel_sum(){
    for(auto item:possibles_sum){
        cout << item << endl;
    }
}

void print_result(){
    cout << result.first << ' ' << result.second << endl;
    for(int i = 1; i <= result.first; i++){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_possibles_sum();
//    print_possibel_sum();
    print_result();
}