#include<iostream>

using namespace std;

int q;
int x;

void answer_the_questions(){
    cin >> q;
    while(q--){
        cin >> x;
        if(__builtin_popcount(2*x-2)%2){
            cout << x*2-1 << endl;
        }
        else{
            cout << x*2-2 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    answer_the_questions();
}