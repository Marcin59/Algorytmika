#include<iostream>
#include<queue>
#include<vector>

using namespace std;
queue<int> the_queue;
const int M = 1e6+3;
int const modulo = 1e9+9;
int number_input_sides[M];
int possibilities[M];
vector<int> graph[M];
vector<int> nodes_in_topologic_sort;
int n, m, U, V;
int a, b;
int actual_element;

void load_data(){
    cin >> n >> m >> U >> V;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
        number_input_sides[b]++;
    }
}

void topologic_sort(){
    for(int i = 1; i <= n; i++){
        if(!number_input_sides[i]){
            the_queue.push(i);
        }
    }
    possibilities[U]++;
    while(!the_queue.empty()){
        actual_element = the_queue.front();
        nodes_in_topologic_sort.push_back(actual_element);
        the_queue.pop();
        for(auto child : graph[actual_element]){
            possibilities[child] += possibilities[actual_element];
            possibilities[child] %= modulo;
            number_input_sides[child]--;
            if(!number_input_sides[child]){
                the_queue.push(child);
            }
        }
    }
    cout << possibilities[V];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    topologic_sort();
}