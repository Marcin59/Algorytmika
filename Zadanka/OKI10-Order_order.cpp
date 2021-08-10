#include<iostream>
#include<vector>

using namespace std;

int const N_LIMIT = 5e5+3;

vector<int> graph[N_LIMIT];
int preorder[N_LIMIT];
int postorder[N_LIMIT];
int actual_preorder = 1;
int actual_postorder = 1;
int n, q;
int a, b;

void dfs(int node){
    preorder[node] = actual_preorder++;
    for(auto child:graph[node]){
        dfs(child);
    }
    postorder[node] = actual_postorder++;
}

void load_data(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a;
        graph[a].push_back(i);
    }
    dfs(0);
}

void make_answer(){
    while(q--){
        cin >> a >> b;
        if(preorder[a] < preorder[b] && postorder[a] > postorder[b]){
            cout << "NIE" << endl;
        }
        else{
            cout << "TAK" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    make_answer();
}