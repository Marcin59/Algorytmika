#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

int const N_LIMIT = 1e4+4;

int values[N_LIMIT];
int max_profit;
vector<int> numbers;
int number_of_deleted;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    while (getline( cin, s ) && !s.empty()){
        numbers.clear();
        number_of_deleted = 0;

        stringstream text_stream(s);
        string item;
        while (getline(text_stream, item, ' ')) {
            numbers.push_back(stoi(item));
        }

        for(int i = 0; i < numbers.size(); ++i){
            values[i-number_of_deleted] = max(0, values[i] + numbers[i]);
            max_profit = max(max_profit, values[i-number_of_deleted]);

            if(numbers[i] == -99){
                number_of_deleted++;
            }
        }
        for (int i = numbers.size() - number_of_deleted; i < numbers.size(); ++i) {
            values[i] = 0;
        }
    }
    cout << max_profit;
}