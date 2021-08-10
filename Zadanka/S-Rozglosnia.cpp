#include<iostream>
#include<vector>
#include<map>

using namespace std;
const int base = 1 << 18;
pair<map<int, int>, map<int, int>> tree[base<<1]; // add elem, remove elem
char actual_change;
map<int, pair<int, int>> result;
int n, m;
int actual_iteration = 0;

void update(int a, int b, int c){
    a += base-2;
    b += base;
    while(b/2 != a/2){
        if(a%2 == 0) {
            if(actual_change == '-'){
                tree[a+1].second[c] =  actual_iteration;
            }
            else{
                tree[a+1].first[c] = actual_iteration;
            }
        }
        if(b%2 == 1){
            if(actual_change == '-'){
                tree[b-1].second[c] = actual_iteration;
            }
            else{
                tree[b-1].first[c] = actual_iteration;
            }
        }
        a /= 2; b /= 2;
    }
}

void add_set(map<int, int> & a){
    for(auto item:a){
        if(result[item.first].second < item.second){
            result[item.first] = {1, item.second};
        }
    }
}

void subtract_set(map<int, int> & a){
    for(auto item:a){
        if(result[item.first].second < item.second){
            result[item.first] = {2, item.second};
        }
    }
}

int query(int index){

    index += base-1;
    result.clear();

    while(index){
        add_set(tree[index].first);
        subtract_set(tree[index].second);
        index /= 2;
    }
    int res = 0;
    for(auto item:result){
        if(item.second.first == 1){
            res++;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int a, b, c;
    while(m--){
        cin >> actual_change;
        if(actual_change == '?'){
            cin >> a;
            cout << query(a) << endl;
        }
        else{
            actual_iteration++;
            cin >> c >> a >> b;
            update(a, b, c);
        }
    }
}