#include<iostream>
#include<map>

using namespace std;
const int M = 3e4 + 5;
bool visited[M];

int main(){
    for(auto & i : visited){
        i = false;
    }
    map<int, int> left_neighbours;
    int n;
    scanf("%i", &n);
    int new_elem;
    for(int i = 1; i <= n; i++){
        scanf("%i", &new_elem);
        left_neighbours[i] = new_elem;
    }
    int result = 0;
    for(int i = 1; i <= n; i++) {
        if (!visited[i]) {
            result++;
        }
        int actual_position = i;
        while(!visited[actual_position]) {
            visited[actual_position] = true;
            actual_position = left_neighbours[actual_position];
            }
    }
    cout << result;
}
