#include<iostream>
#include<set>

using namespace std;
set<int, greater<>> various_value;
int n;
int new_value;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--){
        cin >> new_value;
        various_value.insert(new_value);
        cout << various_value.size() << endl;
    }
}

