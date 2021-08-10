#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int const M = 5e5+5; // maximum shops number
int n; // shops number
int c; // next shop price
int b;
queue<int> the_queue;
vector<int> graph[M];
int number_of_incoming_sides[M];
int increase_prices_right[M];
long long minimum_price = 0;
int actual_node;

void load_data(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c;
        minimum_price += c;
    }
    for(int i = 1; i < n; i++){
        cin >> b;
        increase_prices_right[i] = b;
    }
    for(int i = 1; i < n; i++){
        cin >> b;
        if(increase_prices_right[i] > b){
            graph[i+1].push_back(i);
            number_of_incoming_sides[i]++;
            minimum_price += b;
        }
        else{
            graph[i].push_back(i+1);
            number_of_incoming_sides[i+1]++;
            minimum_price += increase_prices_right[i];
        }
    }
}

void do_topological_sort(){
    for(int i = 1; i <= n; i++){
        if(!number_of_incoming_sides[i]){
            the_queue.push(i);
        }
    }
    while(!the_queue.empty()){
           actual_node = the_queue.front();
           cout << actual_node << ' ';
           the_queue.pop();
           for(int child: graph[actual_node]){
               number_of_incoming_sides[child]--;
               if(!number_of_incoming_sides[child]){
                   the_queue.push(child);
               }
           }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    cout << minimum_price << endl;
    do_topological_sort();
}