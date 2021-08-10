#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int number_of_elems;
int new_elem;
vector<int> list;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> number_of_elems;
    for (int i = 0; i < number_of_elems; ++i) {
        cin >> new_elem;
        list.push_back(new_elem);
    }
    sort(list.begin(), list.end());
    int result = 0;
    long long sum = 0;
    for (int i = number_of_elems-1; i >= 0; --i) {
        cout << sum << endl;
        sum += list[i];
        if(sum >= 0){
            result++;
        }
    }
    cout << result;
}