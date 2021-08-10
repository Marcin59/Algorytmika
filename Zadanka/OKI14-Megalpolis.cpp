#include<iostream>
#include<vector>

using namespace std;

int const base = (1 << 18);
int const M = base+4;
int tree[base << 1];
int parents[M];
int preorders[M];
int preorders_original_index[M];
int last_elem_subtree[M];
int n, m, a, b, k = 0;
char actual_command;
vector<int> graph[M];

void load_ways(){
    cin >> n;
    int i = n;
    while(--i){
        cin >> a >> b;
        graph[a].push_back(b);
        parents[b] = a;
    }
}

void dfs(int node, int depth){
    k++;
    preorders[node] = k;
    preorders_original_index[k] = node;
    tree[k+base-1] = depth;
    for(int &child:graph[node]){
        dfs(child, depth+1);
    }
}

void build_first_results(){
    dfs(1, 0);
}

void build_last_elem_subtree(){
    int actual_node;
    int actual_node_in_preorder;
    for(int i = n; i > 0; i--){
        if(graph[preorders_original_index[i]].empty()){
            actual_node_in_preorder = i;
            actual_node = preorders_original_index[i];
            while(last_elem_subtree[actual_node_in_preorder] < i){
                last_elem_subtree[actual_node_in_preorder] = i;
                actual_node = parents[actual_node];
                actual_node_in_preorder = preorders[actual_node];
            }
        }
    }
}

int query(int index){
    int res = 0;
    index = preorders[index];
    index += base - 1;
    while(index){
        res += tree[index];
        index /= 2;
    }
    return res;
}

void update_tree(int root_subtree){
    root_subtree = preorders[root_subtree];
    int start, end;
    end = base + last_elem_subtree[root_subtree];
    start = base + root_subtree - 2;
    while(start/2 != end/2){
        if(start%2 == 0) tree[start+1] -= 1;
        if(end%2 == 1) tree[end-1] -= 1;
        start /= 2;
        end /= 2;
    }
}

void answer_the_questions(){
    cin >> m;
    int i = n+m;
    while(--i){
        cin >> actual_command;
        if(actual_command == 'A'){
            cin >> a >> b;
            update_tree(b);
        }
        else{
            cin >> a;
            cout << query(a) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_ways();
    build_first_results();
    build_last_elem_subtree();
    answer_the_questions();
}