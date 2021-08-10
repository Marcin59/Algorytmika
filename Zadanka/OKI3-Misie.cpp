#include<iostream>

using namespace std;

#define A1 0
#define A2 1
#define B1 2
#define B2 3


int const modulo = 1e6;
int A1_number;
int A2_number;
int B1_number;
int B2_number;

int bt(int a1, int a2, int b1, int b2, int i, int j)
{
    if (a1 < 0 || a2 < 0 || b1 < 0 || b2 < 0) return 0;
    if (a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0) return 1;
    int sum = 0;

    for(int k = 0; k < 4; k++){
        if (!((((i&1) == (j&1)) && ((j&1) == (k&1))) || (((i&2) == (j&2)) && ((j&2) == (k&2)))))
            sum += bt(a1 - (k==A1), a2 - (k==A2), b1 - (k==B1), b2 - (k==B2), j, k);
    }
    return sum % modulo;
}

void load_data(){
    cin >> A1_number >> A2_number >> B1_number >> B2_number;
    if(A1_number + A2_number + B1_number + B2_number == 1){
        cout << 1 << endl;
        return;
    }
    int sum = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            sum += bt(A1_number - (i == A1) - (j == A1),
                      A2_number - (i == A2) - (j == A2),
                      B1_number - (i == B1) - (j == B1),
                      B2_number - (i == B2) - (j == B2), i, j);
        }
    }
    cout << sum % modulo << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}