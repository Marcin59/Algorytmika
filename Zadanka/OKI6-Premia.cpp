#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int M = 1.5e6+6;
long long sum;
bool possible_sum[M/2];
int divine_smaller, divine_bigger;
vector<int> divines_from_max;
vector<int> divines_from_min;
int n;
int new_elem;

void load_data(){
    cin >> n;
    int i = n;
    int actual_sum = 0;
    while(i--){
        cin >> new_elem;
        actual_sum += new_elem;
        possible_sum[actual_sum] = true;
    }
    sum = actual_sum;
}

void find_all_divines(){
    for(int i = 1; i <= sqrt(sum); i++) {
        if (sum % i == 0) {
            divine_smaller = i;
            divine_bigger = sum / i;
        } else {
            continue;
        }
        if (possible_sum[divine_smaller]) {
            divines_from_min.push_back(divine_smaller);
            for (int j = divine_smaller; j <= sum; j += divine_smaller) {
                if (!possible_sum[j]) {
                    divines_from_min.pop_back();
                    break;
                }
            }
        }
        if (possible_sum[divine_bigger] and divine_smaller != divine_bigger) {
            divines_from_max.push_back(divine_bigger);
            for (int j = divine_bigger; j <= sum; j += divine_bigger) {
                if (!possible_sum[j]) {
                    divines_from_max.pop_back();
                    break;
                }
            }
        }
    }
    for(int i = 0; i < divines_from_min.size(); i++){
        cout << divines_from_min[i] << ' ';
    }

    for(int i = divines_from_max.size()-1; i >= 0; i--){
        cout << divines_from_max[i] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_all_divines();
}