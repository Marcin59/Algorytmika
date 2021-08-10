#include<iostream>

using namespace std;
const int M = 1e6+2;
pair<long long, int> array[M]; // pierwszy element to współczynnik nieporządku od początku ogrodu do indeksu tego elementu, a drugi to liczba wystąpień R przed nim

int main(){
    int n;
    string garden;
    cin >> n;
    cin >> garden;
    int R_count = 0;
    long long actual_factor = 0;
    array[0].first = actual_factor;
    array[0].second = R_count;
    for (int i = 0; i < n; i++)
    {
        if(garden[i] == 'R')
        {
            R_count++;
        }
        else
        {
            actual_factor += R_count;
        }
        array[i+1].first = actual_factor;
        array[i+1].second = R_count;
    }
    long long t;
    cin >> t;
    long long a, b;
    long long result;
    while(t--){
        cin >> a >> b;
        result = array[b].first - array[a-1].first - (b-a+1-array[b].second+array[a-1].second)* array[a-1].second;
        cout << result << endl;
    }
}
