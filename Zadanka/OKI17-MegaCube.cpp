#include<iostream>
#include<unordered_map>
#include<deque>
#include<vector>

using namespace std;

int const C_LIMIT = 1e3+2;
int const modulo = 1e9 + 9;
int const x = 1093;

int cx, cy, mx, my;
vector<long long>power_of_x_array = {1};
int original_matrix[C_LIMIT][C_LIMIT];
long long first_hash_matrix[C_LIMIT][C_LIMIT];

int original_template_matrix[C_LIMIT][C_LIMIT];
long long first_hash_template_matrix[C_LIMIT];
long long the_template;

unordered_map<long long, int> second_hash_matrix;

void update_power_of_x_array(int lenght){
    while(lenght >= power_of_x_array.size()){
        power_of_x_array.push_back((x * power_of_x_array.back() % modulo));
    }
}

long long Hash(deque<int> const& array)
{
    long long hash_val = 0;

    for(int i = 0; i <= array.size()-1; i++){
        hash_val =  (hash_val + array[i] * power_of_x_array[i+1])%modulo;
    }

    return hash_val;
}

void make_first_hash_matrix(){
    deque<int> elements_to_hash;

    for(int j = 1; j <= cy; j++){
        elements_to_hash.clear();
        for(int i = 0; i < mx; i++){
            elements_to_hash.push_back(original_matrix[j][i]);
        }
        for(int i = mx; i <= cx; i++){
            elements_to_hash.pop_front();
            elements_to_hash.push_back(original_matrix[j][i]);
            first_hash_matrix[j][i - mx + 1] = Hash(elements_to_hash);
        }
    }
}

void make_second_hash_matrix(){
    deque<int> elements_to_hash;

    for(int j = 1; j <= cx - mx + 1; j++){
        elements_to_hash.clear();
        for(int i = 0; i < my; i++){
            elements_to_hash.push_back(first_hash_matrix[i][j]);
        }
        for(int i = my; i <= cy; i++){
            elements_to_hash.pop_front();
            elements_to_hash.push_back(first_hash_matrix[i][j]);
            second_hash_matrix[Hash(elements_to_hash)]++;
        }
    }
}

void make_first_template_hash_matrix(){
    deque<int> elements_to_hash;

    for(int j = 1; j <= my; j++){
        elements_to_hash.clear();

        for(int i = 1; i <= mx; i++){
            elements_to_hash.push_back(original_template_matrix[j][i]);
        }
        first_hash_template_matrix[j] = Hash(elements_to_hash);
    }
}

void make_template(){
    deque<int> elements_to_hash;

    for(int i = 1; i <= my; i++){
        elements_to_hash.push_back(first_hash_template_matrix[i]);
    }
    the_template = Hash(elements_to_hash);
}

void load_data(){
    cin >> cx >> cy >> mx >> my;
    update_power_of_x_array(C_LIMIT);
    for(int i = 1; i <= cy; i++){
        for(int j = 1; j <= cx; j++){
            cin >> original_matrix[i][j];
        }
    }
    for(int i = 1; i <= my; i++){
        for(int j = 1; j <= mx; j++){
            cin >> original_template_matrix[i][j];
        }
    }
    make_first_hash_matrix();
    make_second_hash_matrix();
    make_first_template_hash_matrix();
    make_template();
//    cout << "Template ==> " << the_template << endl;
//    cout << "Second hashed elems:" << endl;
//    for(auto item : second_hash_matrix){
//        cout << item.first << " = " << item.second << endl << endl;
//    }
    cout << second_hash_matrix[the_template];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}