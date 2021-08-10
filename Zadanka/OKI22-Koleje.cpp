#include<iostream>

using namespace std;

int n, m ,z;
int const base = 1<<16;

long long tree[base<<1];
long long additional_values[base<<1];


void add_in_sublist(int v, int a, int b, int p, int k, int x){
    if(b<p || k<a) return;
    else if(p <= a && b <= k){
        tree[v] += x;
        additional_values[v] += x;
    }
    else{
        int l = v << 1, r = (v<<1)+1, mid = (a+b)>>1;
        tree[l] += additional_values[v];
        tree[r] += additional_values[v];
        additional_values[l] += additional_values[v];
        additional_values[r] += additional_values[v];
        additional_values[v] = 0;

        add_in_sublist(l, a, mid, p, k, x);
        add_in_sublist(r, mid+1, b, p, k, x);

        tree[v] = max(tree[l], tree[r]);
    }
}

long long max_in_sublist(int v, int a, int b, int p, int k){
    if(b<p || k<a) return 0;
    else if(p <= a && b <= k) return tree[v];
    else{
        int l = v << 1, r = (v<<1)+1, mid = (a+b)>>1;
        tree[l] += additional_values[v];
        tree[r] += additional_values[v];
        additional_values[l] += additional_values[v];
        additional_values[r] += additional_values[v];
        additional_values[v] = 0;

        return max(max_in_sublist(l, a, mid, p, k), max_in_sublist(r, mid+1, b, p, k));
    }
}

void load_data(){
    cin >> n >> m >> z;
}

void answer_the_questions(){
    int a, b, c;
    while(z--){
        cin >> a >> b >> c;
        if(max_in_sublist(1, 0, base-1, a, b-1) + c <= m){
            add_in_sublist(1, 0, base-1, a, b-1, c);
            cout << "T" << endl;
        }
        else cout << "N" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    answer_the_questions();
}