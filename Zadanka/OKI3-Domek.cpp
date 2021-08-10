#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

int n, k;
int const M = 1.5e5;
int binary_tree[M];
int nodes_number;
vector<int> results[M];

void print_results(){
    for(const auto& item:results){
        for(auto r:item){
            cout << r << " ";
        }
        cout << endl;
    }
}
int parent(int i){
    return i/2;
}

int left_child(int i){
    return i*2;
}

int right_child(int i){
    return i*2+1;
}

int find_result(int node, int c){
    c--;
    int max_sum = results[node][c-1];
    if(right_child(node) <= nodes_number)
        for(int i = 0; i <= c; i++){
            max_sum = max(max_sum, binary_tree[node] + results[left_child(node)][i] + results[right_child(node)][c-i]);
        }
    return max_sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(auto & result : results){
        result.assign(45, 0);
    }
    cin >> n >> k;
    k /= 2;

    nodes_number = pow(2, n)-1;

    int a, b;
    for(int i = 1; i <= nodes_number; i++){
        cin >> a >> b;
        binary_tree[i] = a+b;
    }
    for(int i = 1; i <= nodes_number; i++){
        results[i][0] = 0;
        results[i][1] = max(0, binary_tree[i]);
    }

    for(int j = 2; j <= k; j++){
        for(int i = 1; i <= nodes_number; i++){
            results[i][j] = find_result(i, j);
        }
    }
    cout << results[1][k];
}

/*

3 6
1 -3
-10 1 2 1
1 1 3 2 -1 5 2 -3

 4 20
 2 -1
-3 -2 -2 10
2 -3 -3 -2 -1 -2 1 10
1 2 -1 -2 9 8 -1 -4 3 4 2 3 -1 -5 -1 -6

 */