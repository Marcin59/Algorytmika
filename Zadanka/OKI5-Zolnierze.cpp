#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int, int> number_of_apperances;
int n;
int new_elem;
int result = 2;
int modulo = 1e4;

void load_data(){
    cin >> n;
    while(n--){
        cin >> new_elem;
        number_of_apperances[new_elem]++;
        result *= number_of_apperances[new_elem];
        result %= modulo;
    }
    if(number_of_apperances.size() == 1){
        cout << result/2 << endl;
        return;
    }
    if(result == 0){
        cout << "0000" << endl;
        return;
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}