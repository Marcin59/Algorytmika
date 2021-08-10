#include<iostream>

using namespace std;
int const M = 1e6+3;
int iq_min[M];
int iq_max[M];
int colony_weight[M];
int parents[M];
int deph[M];
int n;
int a, b;

int find(int a){
    if(parents[a] != a){
        return find(parents[a]);
    }
    else{
        return a;
    }
}

void the_union(int a, int b){
    int parent1 = find(a);
    int parent2 = find(b);
    if(parent1 == parent2) return;
    if(deph[parent1] < deph[parent2]){
        int prev = parent1;
        parent1 = parent2;
        parent2 = prev;
    }
    parents[parent2] = parent1;
    colony_weight[parent1] += colony_weight[parent2];
    iq_max[parent1] = max(iq_max[parent1], iq_max[parent2]);
    iq_min[parent1] = min(iq_min[parent1], iq_min[parent2]);
    if(deph[parent1] == deph[parent2]){
        deph[parent1]++;
    }
}

void load_data(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        parents[i] = i;
        colony_weight[i] = a;
        iq_min[i] = b;
        iq_max[i] = b;
    }
}

void answer_the_question(){
    string actual_order;
    while(cin >> actual_order && actual_order.size()){
        if(actual_order == "JOIN"){
            cin >> a >> b;
            the_union(a, b);
        }
        else{
            cin >> a;
            a = find(a);
            if(actual_order == "IQ_MIN"){
                cout << iq_min[a] << endl;
            }
            else if(actual_order == "IQ_MAX"){
                cout << iq_max[a] << endl;
            }
            else{
                cout << colony_weight[a] << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    answer_the_question();
}