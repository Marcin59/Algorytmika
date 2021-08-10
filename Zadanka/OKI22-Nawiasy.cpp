#include<iostream>

using namespace std;

int n;
int const base = 1<<17;
int const N_limit = 1e5+4;

long long tree[base<<1];
long long additional_values[base<<1];
int brackets[N_limit];

int open_brackets;
int close_brackets;

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

        tree[v] = min(tree[l], tree[r]);
    }
}

long long min_in_sublist(int v, int a, int b, int p, int k){
    if(b<p || k<a) return 0;
    else if(p <= a && b <= k) return tree[v];
    else{
        int l = v << 1, r = (v<<1)+1, mid = (a+b)>>1;
        tree[l] += additional_values[v];
        tree[r] += additional_values[v];
        additional_values[l] += additional_values[v];
        additional_values[r] += additional_values[v];
        additional_values[v] = 0;

        return min(min_in_sublist(l, a, mid, p, k), min_in_sublist(r, mid+1, b, p, k));
    }
}

void load_data(){
    cin >> n;
    int new_bracket;
    for(int i = 1; i<= n; i++){
        cin >> new_bracket;
        if(new_bracket == 1){
            open_brackets++;
        }
        else{
            close_brackets++;
        }
        add_in_sublist(1, 0, base-1, i, n, new_bracket);
        brackets[i] = new_bracket;
    }
}

void answer_the_questions(){
    int new_questions;
    cin >> new_questions;

    while(new_questions != -1){
        if(new_questions == 0){
            if(min_in_sublist(1, 0, base-1, 1, base-1) >= 0 && open_brackets == close_brackets){
                cout << "TAK" << endl;
            }
            else{
                cout << "NIE" << endl;
            }
        }
        else{
            if(brackets[new_questions] == -1){
                brackets[new_questions] = 1;
                add_in_sublist(1, 0, base-1, new_questions, n, 2);
                open_brackets++;
                close_brackets--;
            }
            else{
                brackets[new_questions] = -1;
                add_in_sublist(1, 0, base-1, new_questions, n, -2);
                open_brackets--;
                close_brackets++;
            }
        }
        cin >> new_questions;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    answer_the_questions();
}