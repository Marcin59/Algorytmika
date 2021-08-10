#include<iostream>
#include<queue>
#include<vector>

using namespace std;
queue<int> the_queue;
const int M = 1e6+3;
int number_input_sides[M];
vector<int> graph[M];
int n, m;
int a, b;
int actual_element;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
        number_input_sides[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(!number_input_sides[i]){
            the_queue.push(i);
        }
    }
    while(!the_queue.empty()){
        actual_element = the_queue.front();
        cout << actual_element << " ";
        the_queue.pop();
        for(auto child : graph[actual_element]){
            number_input_sides[child]--;
            if(!number_input_sides[child]){
                the_queue.push(child);
            }
        }
    }
}