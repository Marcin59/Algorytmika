#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<long long> h;
int n;
string str;
int questions;
int a, b;

void hash_string(){
    h.push_back(0);
    for(char i : str){
        h.push_back(h.back()+i);
    }
}

long long calculate_value_hash_substring(int i, int j){
    return h[j] - h[i-1];
}

void load_data(){
    cin >> n;
    cin >> str;
}

void answer_the_questions(){
    cin >> questions;
    bool result;
    long long finding_sum;
    int len_of_finding_substring;
    while(questions--){
        cin >> a >> b;
        result = false;
        finding_sum = calculate_value_hash_substring(a, b-1)*2;
        len_of_finding_substring = (b - a)*2-1;
        cout << "Finding sum: " << finding_sum << endl;
        cout << "Visited sum:" << endl;
        for(int i = 1; i <= n - len_of_finding_substring; i++){
            cout << calculate_value_hash_substring(i, i + len_of_finding_substring) << ' ';
            if(calculate_value_hash_substring(i, i + len_of_finding_substring) == finding_sum){
                result = true;
                break;
            }
        }
        cout << endl;
        if(result){
            cout << "TAK" << endl << endl;
        }
        else{
            cout << "NIE" << endl << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    hash_string();
    answer_the_questions();
}