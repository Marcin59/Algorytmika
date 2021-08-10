#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

int n, s;
int new_poem;
vector<int> poems;
unordered_map<int, vector<int>> places;
int actual_place = 1;
int actual_rows_in_page = 0;
int number_of_free_rows = 0;
unordered_map<int, int> apperances_of_poems;
priority_queue<pair<int, int>> the_priority_queue;

void load_data(){
    cin >> n >> s;
    int x = n;
    while(x--){
        cin >> new_poem;
        new_poem++;
        new_poem %= s;
        if(new_poem == 0){
            places[new_poem].push_back(actual_place++);
        }
        poems.push_back(new_poem);
        apperances_of_poems[new_poem]++;
    }

    pair<int, int> new_elem_for_priority_queue;
    for(auto item:apperances_of_poems){
        new_elem_for_priority_queue.first = item.second;
        new_elem_for_priority_queue.second = item.first;
        the_priority_queue.emplace(new_elem_for_priority_queue);
    }

//    while(!the_priority_queue.empty()){
//        cout << the_priority_queue.top().first << ' ' << the_priority_queue.top().second << endl;
//        the_priority_queue.pop();
//    }
}

void find_places(){
    pair<int, int> item1, item2;
    pair<int, int> new_elem_for_priority_queue;
    while(!the_priority_queue.empty()){
        item1 = the_priority_queue.top();
        the_priority_queue.pop();
        if(actual_rows_in_page + item1.second == s-1 && !the_priority_queue.empty()){

            item2 = the_priority_queue.top();
            the_priority_queue.pop();

            actual_rows_in_page = (actual_rows_in_page + item1.second) % s;
            places[item2.second].push_back(actual_place++);

            if(item2.first > 1){
                new_elem_for_priority_queue.first = item2.first-1;
                new_elem_for_priority_queue.second = item2.second;
                the_priority_queue.emplace(new_elem_for_priority_queue);
            }
            the_priority_queue.emplace(item1);

        }
        else{
            actual_rows_in_page = (actual_rows_in_page + item1.second) % s;
            if(actual_rows_in_page == s-1 && actual_place != n){
                number_of_free_rows++;
                actual_rows_in_page = 0;
            }
            places[item1.second].push_back(actual_place++);
            if(item1.first > 1){
                new_elem_for_priority_queue.first = item1.first-1;
                new_elem_for_priority_queue.second = item1.second;
                the_priority_queue.emplace(new_elem_for_priority_queue);
            }
        }
    }
}

void print_result(){
    cout << number_of_free_rows << endl;
    for(auto item:poems){
        cout << places[item].back() << ' ';
        places[item].pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_places();
    print_result();
}