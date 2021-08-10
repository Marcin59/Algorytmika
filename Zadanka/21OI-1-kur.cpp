#include<iostream>
#include<vector>
#include<map>

using namespace std;

int const base = 1<<19;
pair<int, int> tree[base<<1]; // value, times lider
map<int, int> appearances_numbers[base];
int couriers_number;

int n, m;

void add_value(int index, int value){
    index += base-1;
    tree[index].first = value;
    tree[index].second = 1;
    while(index/2){
         if(tree[index/2].first == value){
             tree[index/2].second++;
         }
         else if(tree[index/2].second){
             tree[index/2].second--;
         }
         else{
             tree[index/2].first = value;
             tree[index/2].second = 1;
         }
        index /= 2;
    }
}

void load_data(){
    cin >> n >> m;
    couriers_number = 0;
    int new_value;
    for(int i = 1; i <= n; i++){
        cin >> new_value;
        add_value(i, new_value);
        couriers_number = max(couriers_number, new_value);
    }
}

void make_appearances_numbers(){
    map<int, int> actual_map;
    appearances_numbers[0] = actual_map;
    for(int i = 1; i <= n; i++){
        actual_map[tree[i+base-1].first]++;
        appearances_numbers[i] = actual_map;
    }
}

int find_leader(int start, int end){

    start += base-2;
    end += base;

    int value = 0;
    int times = 0;
    while(start/2 != end/2){
        if(start%2 == 0){
            if(tree[start+1].first == value){
                times += tree[start+1].second;
            }
            else if(tree[start+1].second > times){
                value = tree[start+1].first;
                times = tree[start+1].second - times;
            }
            else{
                times -= tree[start+1].second;
            }
        }
        if(end%2 == 1){
            if(tree[end-1].first == value){
                times += tree[end-1].second;
            }
            else if(tree[end-1].second > times){
                value = tree[end-1].first;
                times = tree[end-1].second - times;
            }
            else{
                times -= tree[end-1].second;
            }
        }
        start /= 2;
        end /= 2;
    }

    if(!times){
        return 0;
    }
    return value;
}

void print_result(){
    int a, b;
    int candidate;
    int count;
    while(m--){
        cin >> a >> b;
        candidate =  find_leader(a, b);
        if(!candidate){
            cout << 0 << endl;
            continue;
        }
        count = appearances_numbers[b][candidate] - appearances_numbers[a-1][candidate];
        if(count > (b - a+1)/2){
            cout << candidate << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_appearances_numbers();
    print_result();
}