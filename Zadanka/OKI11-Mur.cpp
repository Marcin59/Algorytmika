#include<iostream>

using namespace std;

int cities_number;
int n, x, y;
int state;
pair<long long, long long> vector1, vector2;
int a, b;

void answer_the_qestion(){
    cin >> n >> x >> y;
    cin >> a >> b;
    vector1.first = a - x;
    vector1.second = b - y;
    cin >> a >> b;
    vector2.first = a - x;
    vector2.second = b - y;
    if(vector1.first*vector2.second-vector1.second*vector2.first == 0){
        cout << "NIE" << endl;
        return;
    }
    if(vector1.first*vector2.second-vector1.second*vector2.first<0){
        state = 1;
    }
    else state = 0;
    for(int i = 2; i < n; i++){
        vector1 = vector2;
        cin >> a >> b;
        vector2.first = a - x;
        vector2.second = b - y;
        if(state == 1){
            if(vector1.first*vector2.second-vector1.second*vector2.first>=0){
                for(int j = i+1; j < n; j++){
                    cin >> a >> b;
                }
                cout << "NIE" << endl;
                return;
            }
        }
        else{
            if(vector1.first*vector2.second-vector1.second*vector2.first<=0){
                for(int j = i+1; j < n; j++){
                    cin >> a >> b;
                }
                cout << "NIE" << endl;
                return;
            }
        }
    }
    cout << "TAK" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> cities_number;
    while(cities_number--){
        answer_the_qestion();
    }
}