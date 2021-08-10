#include<iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int result = 0;
    long long k = 1;
    while( k <= n){
        result++;
        n -= k;
        k *= 2;
    }
    while(n > 0){
        if (n%2 == 1){
        result++;
        }
        n /= 2;
    }
    cout << result;
}