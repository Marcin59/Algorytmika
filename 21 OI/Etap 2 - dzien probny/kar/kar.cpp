#include<iostream>
#include<climits>

using namespace std;

struct Node {
    bool xx;
    bool xy;
    bool yy;
    bool yx;
    int depth;
};

struct Leaf {
    int x;
    int y;
};

int const tree_size = 1 << 18;
int const tree_depth = 19;
Node nodes[tree_size];
Leaf leafs[tree_size];
int number_of_cards;
int actual_x, actual_y;

void load_cards(){
    cin >> number_of_cards;
    for (int i = 0; i < number_of_cards; ++i) {
        cin >> actual_x >> actual_y;
        leafs[i].x = actual_x;
        leafs[i].y = actual_y;
    }
    for (int i = number_of_cards; i < tree_size; ++i) {
        leafs[i].x = INT_MAX;
        leafs[i].y = INT_MAX;
    }
}

int find_leaf_index(int index, int depth){
    index = index*(1 << (tree_depth - depth)) + (1 << (tree_depth - depth -1)) -1;
    return (index%tree_size);
}

void update_node(int i){
    int leaf_index = find_leaf_index(i, nodes[i].depth);
    if (i*2 >= tree_size){
        nodes[i].xx = leafs[leaf_index].x <= leafs[leaf_index+1].x;
        nodes[i].xy = leafs[leaf_index].x <= leafs[leaf_index+1].y;
        nodes[i].yy = leafs[leaf_index].y <= leafs[leaf_index+1].y;
        nodes[i].yx = leafs[leaf_index].y <= leafs[leaf_index+1].x;
    }
    else{
        nodes[i].xx = (nodes[i*2].xx && nodes[i*2+1].xx && (leafs[leaf_index].x <= leafs[leaf_index+1].x)) ||
                      (nodes[i*2].xx && nodes[i*2+1].yx && (leafs[leaf_index].x <= leafs[leaf_index+1].y)) ||
                      (nodes[i*2].xy && nodes[i*2+1].xx && (leafs[leaf_index].y <= leafs[leaf_index+1].x)) ||
                      (nodes[i*2].xy && nodes[i*2+1].yx && (leafs[leaf_index].y <= leafs[leaf_index+1].y));

        nodes[i].yy = (nodes[i*2].yy && nodes[i*2+1].yy && (leafs[leaf_index].y <= leafs[leaf_index+1].y)) ||
                      (nodes[i*2].yy && nodes[i*2+1].xy && (leafs[leaf_index].y <= leafs[leaf_index+1].x)) ||
                      (nodes[i*2].yx && nodes[i*2+1].yy && (leafs[leaf_index].x <= leafs[leaf_index+1].y)) ||
                      (nodes[i*2].yx && nodes[i*2+1].xy && (leafs[leaf_index].x <= leafs[leaf_index+1].x));

        nodes[i].xy = (nodes[i*2].xy && nodes[i*2+1].yy && (leafs[leaf_index].y <= leafs[leaf_index+1].y)) ||
                      (nodes[i*2].xy && nodes[i*2+1].xy && (leafs[leaf_index].y <= leafs[leaf_index+1].x)) ||
                      (nodes[i*2].xx && nodes[i*2+1].yy && (leafs[leaf_index].x <= leafs[leaf_index+1].y)) ||
                      (nodes[i*2].xx && nodes[i*2+1].xy && (leafs[leaf_index].x <= leafs[leaf_index+1].x));

        nodes[i].yx = (nodes[i*2].yy && nodes[i*2+1].yx && (leafs[leaf_index].y <= leafs[leaf_index+1].y)) ||
                      (nodes[i*2].yy && nodes[i*2+1].xx && (leafs[leaf_index].y <= leafs[leaf_index+1].x)) ||
                      (nodes[i*2].yx && nodes[i*2+1].yx && (leafs[leaf_index].x <= leafs[leaf_index+1].y)) ||
                      (nodes[i*2].yx && nodes[i*2+1].xx && (leafs[leaf_index].x <= leafs[leaf_index+1].x));
    }
}

void prepare_tree(){
    nodes[1].depth = 1;
    for(int i = 1; i <= tree_size/2 - 1; ++i){
        nodes[i*2].depth = nodes[i].depth + 1;
        nodes[i*2+1].depth = nodes[i].depth + 1;
    }
    for (int i = tree_size-1; i > 0; --i) {
        update_node(i);
    }
}

void print_actual_result(){
    if(nodes[1].xx || nodes[1].xy || nodes[1].yy || nodes[1].yx){
        cout << "TAK" << endl;
    }
    else cout << "NIE" << endl;
}

void change_cards_and_update_tree(int card1, int card2){
    card1--;
    card2--;
    Leaf pre_card = leafs[card1];
    leafs[card1] = leafs[card2];
    leafs[card2] = pre_card;
    card1 = (card1 + tree_size)/2;
    card2 = (card2 + tree_size)/2;
    while(card1 > 0){
        update_node(card1);
        card1 /= 2;
    }
    while(card2 > 0){
        update_node(card2);
        card2 /= 2;
    }
}

void load_changes(){
    int number_of_changes;
    cin >> number_of_changes;
    int a, b;
    for (int i = 0; i < number_of_changes; ++i) {
        cin >> a >> b;
        change_cards_and_update_tree(a, b);
        print_actual_result();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_cards();
    prepare_tree();
    load_changes();
}

