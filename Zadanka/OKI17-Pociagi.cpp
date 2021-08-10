#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

int const N_LIMIT = 1e3+2;
int const modulo = 1e9 + 9;
int const x = 31;
int results[N_LIMIT];
string trains[N_LIMIT];
int h[N_LIMIT];
unordered_map<int, unordered_map<int, bool>> hashed_trains;
vector<int>power_of_x_array = {1};
int n, l, m;
int a, b, c, d;

void update_power_of_x_array(int lenght){
    while(lenght >= power_of_x_array.size()){
        power_of_x_array.push_back((x * power_of_x_array.back() % modulo));
    }
}

long long Hash(string const& str)
{
    long long hash_val = 0;

    for(int i = 0; i < str.size(); i++){
        hash_val = (hash_val + str[i] * power_of_x_array[i]) % modulo;
    }

//    cout << "Hash of '" << str << "' = " << hash_val << endl;
    return hash_val;
}

void load_data(){
    cin >> n >> l >> m;
    update_power_of_x_array(l);
    string str;
    int str_in_hash;
    for(int i = 1; i <= n; i++){
        cin >> str;
        trains[i] = str;
        str_in_hash = Hash(str);
        hashed_trains[str_in_hash][i] = true;
        h[i] = str_in_hash;
    }
    for(int i = 1; i <= n; i++){
        results[i] = hashed_trains[h[i]].size();
    }
    while(m--){
        cin >> a >> b >> c >> d;
        if(trains[a][b-1] == trains[c][d-1]) continue;
        swap(trains[a][b-1], trains[c][d-1]);
        hashed_trains[h[a]].erase(a);
        hashed_trains[h[c]].erase(c);
        h[a] = Hash(trains[a]);
        hashed_trains[h[a]][a] = true;
        h[c] = Hash(trains[c]);
        hashed_trains[h[c]][c] = true;
        for(auto train:hashed_trains[h[a]]){
            results[train.first] = max(results[train.first], (int)hashed_trains[h[a]].size());
        }
        for(auto train:hashed_trains[h[c]]){
            results[train.first] = max(results[train.first], (int)hashed_trains[h[c]].size());
        }
    }
}

void print_result(){
    for(int i = 1; i <= n; i++){
        cout << results[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    print_result();
}