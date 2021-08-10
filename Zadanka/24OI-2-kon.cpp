#include<iostream>
#include<cmath>
#include<unordered_map>

using namespace std;

int const N_LIMIT = 1e5+2;
int n, k;
int a, l, d;
int number_of_conteiners_brutal[N_LIMIT];
unordered_map<int, int[N_LIMIT]> prefixes;

void brutal_add(){
    for(int i = a; i < a+l*d; i += d){
        number_of_conteiners_brutal[i]++;
    }
}

void fast_add(){
    prefixes[d][a]++;
    prefixes[d][a+l*d]--;
}

void add_new_conteiners(){
    if(d > sqrt(n)){
        brutal_add();
    }
    else{
        fast_add();
    }
}

void load_data(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        cin >> a >> l >> d;
        add_new_conteiners();
    }
}

void count_prefixes(){
    for(auto &prefix:prefixes){
        for(int i = prefix.first; i <= n; i++){
            prefix.second[i] += prefix.second[i-prefix.first];
        }
    }
}

void print_answer(){
    int actual_result;
    for(int i = 1; i<= n; i++){
        actual_result = 0;
        actual_result += number_of_conteiners_brutal[i];
        for(auto &prefix:prefixes){
            actual_result += prefix.second[i];
        }
        cout << actual_result << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    count_prefixes();
    print_answer();
}