#include<iostream>

using namespace std;

int numbers;
int result = 0;
int n;

int main(){
    scanf("%d", &numbers);
    while(numbers--){
        scanf("%d", &n);
        result ^= n;
    }
    printf("%d", result);
}