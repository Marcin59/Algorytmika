#include<iostream>

using namespace std;

int number_of_questions;
long long n, a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> number_of_questions;
    for (int i = 0; i < number_of_questions; ++i) {
        cin >> n >> a >> b;
        long long divider = 1;
        if(a != 1) {
            while (divider * a <= n) {
                divider *= a;
            }
        }
        cout << divider << endl;
        n -= divider;
        cout << n << endl;
        cout << n%b << endl;
        if(n%b == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
