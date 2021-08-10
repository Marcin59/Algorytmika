#include<iostream>

using namespace std;

int const M = 1<<20;
long long tree[M];
int number_of_new_facture = 1;


int pot(int x){
    return x & -x;
}

long long beforeeq(int x){
    long long sum = 0;
    while(x > 0){
        sum += tree[x];
        x -= pot(x);
    }
    return sum;
}

long long beetween(int x, int y){
    return beforeeq(y) - beforeeq(x-1);
}

void update(int x, int cnt){
    while(x <= M){
        tree[x] += cnt;
        x += pot(x);
    }
}

void inicjuj(int m){
    }

void dodaj(int k){
    update(number_of_new_facture, k);
    number_of_new_facture++;
}

void koryguj(int i, int k){
    update(number_of_new_facture-i, k);
}

long long suma(int i){
    return beetween(max(1, number_of_new_facture-i), number_of_new_facture-1);
}

//int main(){
//    dodaj(-6);
//    cout << suma(1) << endl;
//    dodaj(5);
//    koryguj(2, 10);
//    cout << suma(3) << endl;
//    cout << suma(1) << endl;
//    cout << suma(10) << endl;
//    cout << suma(2) << endl;
//
//    koryguj(1, 10);
//    cout << suma(1) << endl;
//}