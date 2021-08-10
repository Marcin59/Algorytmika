#include<iostream>
#include<queue>
#include<vector>
#include<bitset>

using namespace std;

vector<bitset<20>> masks = {0};
vector<int> changes = {0};
queue<pair<bitset<20>, int>> the_queue; // mask, value
int n;
int new_elem;

void load_data(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> new_elem;
        changes.push_back(new_elem);
    }

    for(int i = 1; i <= 1<<20; i*=2){
        masks.push_back(i);
    }

}

void find_posibilities(){
    the_queue.push({0, 0});

    int max_mask = (1 << n)-1;
    int result = 0;

    bitset<20> mask;
    int actual_value;
    while(!the_queue.empty()){
        mask = the_queue.front().first;
        actual_value = the_queue.front().second;
        the_queue.pop();

        if(mask == max_mask){
            result++;
        }

        for(int i = 1; i <= n; i++){
            if((masks[i]&mask).none() && actual_value + changes[i] >= 0){
                the_queue.push({masks[i]|mask, actual_value + changes[i]});
            }
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_posibilities();
}