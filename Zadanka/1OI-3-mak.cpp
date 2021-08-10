#include<iostream>
#include<vector>

using namespace std;
int n;
const int base = 20;
vector<int> results[base];
vector<int> prev_results[base];
int prev_costs[base];
int costs[base];
vector<vector<int>> degrees;
int a, b;
bool possible[base];
bool prev_possible[base];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--){
        cin >> a;
        degrees.push_back({a});
        if(a < 0){
            cin >> b;
            degrees.back().push_back(b);
        }
    }
    for(bool & i : possible){
        i = true;
    }
    while(!degrees.empty()){
        auto actual_data = degrees.back();
        degrees.pop_back();
        if(actual_data.front() > 0){
            for(int i = base-1; i >= 0; i--){
                if(i - actual_data.front() >= 0){
                    if(possible[i - actual_data.front()]){
                        possible[i] = true;
                        costs[i] = costs[i - actual_data.front()] + actual_data.front();
                        results[i] = results[i - actual_data.front()];
                        results[i].push_back(actual_data.front());
                    }
                    else{
                        possible[i] = false;
                    }
                }
                else{
                    possible[i] = false;
                }
            }
        }
        else{
            for(int i = 0; i < base; i++){
                prev_costs[i] = costs[i];
                prev_possible[i] = possible[i];
                prev_results[i] = results[i];
            }

            for(int i = 0; i < base; i++){
                if(i - actual_data.front() < base){
                    if(possible[i - actual_data.front()]){
                        possible[i] = true;
                        costs[i] = costs[i - actual_data.front()] - actual_data.front();
                        results[i] = results[i - actual_data.front()];
                        results[i].push_back(actual_data.front());
                    }
                    else{
                        possible[i] = false;
                    }
                }
                else{
                    possible[i] = false;
                }
            }

            for(int i = base-1; i >= 0; i--){
                if(i - actual_data.back() >= 0){
                    if(prev_possible[i - actual_data.back()]){
                        if(!possible[i] || prev_costs[i - actual_data.back()] + actual_data.back() < costs[i]) {
                            possible[i] = true;
                            costs[i] = prev_costs[i - actual_data.back()] + actual_data.back();
                            results[i] = prev_results[i - actual_data.back()];
                            results[i].push_back(actual_data.back());
                        }
                    }
                }
            }
        }
    }
    for(int i = base-1; i >= 0; i--){
        if(possible[i]){
            for(int j = (int)results[i].size()-1; j >= 0; j--){
                cout << results[i][j] << ' ';
            }
            cout << endl;
        }
        else{
            cout << "NIE" << endl;
        }
    }
}