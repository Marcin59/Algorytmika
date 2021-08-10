#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const base = 1<<14;
int tree[base<<1]; // tree with max of sublists
int width, height;
int n;
int new_x, new_y;
vector<vector<int>> co_ordinates;

bool the_key(vector<int> const & a, vector<int> const & b){
    if (a[1] != b[1]){
        return a[1] < b[1];
    }
    else{
        return a[2] > b[2];
    }
}

void load_data(){
    cin >> width >> height;
    cin >> n;
    while(n--){
        cin >> new_x >> new_y;
        co_ordinates.push_back({new_x, new_y, 1});
        co_ordinates.push_back({new_x, new_y+height, -1});
    }
    sort(co_ordinates.begin(), co_ordinates.end(), the_key);
    for(auto item:co_ordinates){
        cout << "X: " << item[0] << "  Y: " << item[1] << "  Z: " << item[2] << endl;
    }
}

void propagate(int index){
    tree[2*index] =
}

void update(int start, int end, int value){

}

int query(int start, int end){
   return 0;
}

void find_result(){
    int result = 0;
    for(auto item:co_ordinates){
        update(item[0], item[0] + width, item.back());
        result = max(result, query(1, base));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_result;
}