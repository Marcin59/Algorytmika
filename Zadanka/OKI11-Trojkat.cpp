#include<iostream>

using namespace std;

int x1, x2, x3, y1, y2, y3;
pair<long long , long long> vector1, vector2;

int main(){
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    vector1.first  = x2-x1;
    vector1.second = y2-y1;
    vector2.first = x3-x1;
    vector2.second = y3 - y1;
    if(vector1.first*vector2.second-vector1.second*vector2.first<0){
        cout << "ZGODNIE";
    }
    else{
        cout << "PRZECIWNIE";
    }
}