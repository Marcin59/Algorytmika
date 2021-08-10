#include<iostream>
#include<map>
#include<string>

using namespace std;

int n;
map<char, int> global_letters_count, actual_letters_count;
string actual_word;
char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> actual_word;
    for(char letter:actual_word){
        global_letters_count[letter]++;
    }
    n--;
    while(n--){
        cin >> actual_word;
        for(char letter:actual_word){
            actual_letters_count[letter]++;
        }
        for(auto &item:global_letters_count){
            item.second = min(item.second, actual_letters_count[item.first]);
        }
    }
    for(auto &item:global_letters_count){
        for(int i = 0; i < item.second; i++){
            cout << item.first;
        }
    }
}