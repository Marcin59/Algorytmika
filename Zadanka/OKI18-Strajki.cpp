#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
int const N_LIMIT = 5e5+2;
unordered_map<int, int> input_sides;
vector<int> graph[N_LIMIT];
int result = 1;
int nodes;
int a, b;
int questions;
int change_node;

void load_data(){
    cin >> nodes;
    for(int i = 1; i < nodes; i++){
        cin >> a >> b;
        input_sides[a]++;
        input_sides[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void answer_the_questions(){
    cin >> questions;
    while (questions--){
        cin >> change_node;
        if(change_node > 0){
            result += input_sides[change_node]-1;
            for(auto node:graph[change_node]){
                input_sides[node]--;
            }
        }
        else{
            result -= input_sides[-change_node]-1;
            for(auto node:graph[-change_node]){
                input_sides[node]++;
            }
        }
        cout << result << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    answer_the_questions();
}