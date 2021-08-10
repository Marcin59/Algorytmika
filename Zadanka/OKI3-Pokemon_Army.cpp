#include<iostream>

using namespace std;

int injuries_number;
int count = 0;
int numbers_count, last_number = 0, number;
int zero;
long long result;

void find_and_write_result(){
    result = 0;
    count = 0;
    last_number = 0;
    cin >> numbers_count >> zero;
    while(numbers_count--){
        cin >> number;
        if(count%2 == 0){
            if(number<last_number){
                result += last_number;
                count ++;
            }
            else if(numbers_count == 0){
                result += number;
            }
        }
        else{
            if(number > last_number){
                result -= last_number;
                count++;
                if(numbers_count == 0){
                    result += number;
                }
            }
        }
        last_number = number;
    }
    cout << result << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> injuries_number;
    while(injuries_number--){
        find_and_write_result();
    }
}