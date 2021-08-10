#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int n;
vector<string> strings;
string new_string;

bool key(const string a, const string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--) {
        cin >> new_string;
        strings.push_back(new_string);
    }
    sort(strings.begin(), strings.end(), key);
    for(const string& item:strings){
        cout << item << endl;
    }
}