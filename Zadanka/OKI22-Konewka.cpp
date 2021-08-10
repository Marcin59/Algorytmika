#include<iostream>

using namespace std;

int const base = 1 << 19;

int tree_with_max_weight[base << 1];
int tree_with_max_weight_additional_values[base << 1];
int number_of_trees, max_tree_height;

void add_in_sublist(int v, int a, int b, int p, int k, int x){
    if(b<p || k<a) return;
    else if(p <= a && b <= k){
        tree_with_max_weight[v] += x;
        tree_with_max_weight_additional_values[v] += x;
    }
    else{
        int l = v << 1, r = (v<<1)+1, mid = (a+b)>>1;
        tree_with_max_weight[l] += tree_with_max_weight_additional_values[v];
        tree_with_max_weight[r] += tree_with_max_weight_additional_values[v];
        tree_with_max_weight_additional_values[l] += tree_with_max_weight_additional_values[v];
        tree_with_max_weight_additional_values[r] += tree_with_max_weight_additional_values[v];
        tree_with_max_weight_additional_values[v] = 0;

        add_in_sublist(l, a, mid, p, k, x);
        add_in_sublist(r, mid+1, b, p, k, x);

        tree_with_max_weight[v] = max(tree_with_max_weight[l], tree_with_max_weight[r]);
    }
}

long long max_in_sublist(int v, int a, int b, int p, int k){
    if(b<p || k<a) return 0;
    else if(p <= a && b <= k) return tree_with_max_weight[v];
    else{
        int l = v << 1, r = (v<<1)+1, mid = (a+b)>>1;
        tree_with_max_weight[l] += tree_with_max_weight_additional_values[v];
        tree_with_max_weight[r] += tree_with_max_weight_additional_values[v];
        tree_with_max_weight_additional_values[l] += tree_with_max_weight_additional_values[v];
        tree_with_max_weight_additional_values[r] += tree_with_max_weight_additional_values[v];
        tree_with_max_weight_additional_values[v] = 0;

        return max(max_in_sublist(l, a, mid, p, k), max_in_sublist(r, mid+1, b, p, k));
    }
}

void inincjuj(int n, int k, int *D){
    number_of_trees = n;
    max_tree_height = k;
    int *ptr;
    ptr = D;
    for(int i = 0; i<n; i++){
        tree_with_max_weight[i+base+1] = ptr[i];
    }
    for(int i = base-2; i >= 0; i--){
        tree_with_max_weight[i] = max(tree_with_max_weight[ i << 1], tree_with_max_weight[(i<<1)+1]);
    }
}

void podlej(int a, int b){
    add_in_sublist(1, 0, base-1, a, b, 1);
    while(max_in_sublist(1, 0, base-1, 0, base-1) > max_tree_height){

    }
}

int main(){
    int val[3] = { 5, 10, 20 };
    inincjuj(3, 3, val);
}