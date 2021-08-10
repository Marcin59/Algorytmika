#include<iostream>
#include<vector>

using namespace std;

int const N_LIMIT = 52;

int t;
int n, m;
char new_elem;
char matrix[N_LIMIT][N_LIMIT];
bool visited[N_LIMIT][N_LIMIT];
int number_of_good_boys;
int found_good_boys;
vector<pair<int, int>> bad_boys_locations;

void reset_matrix(){
    for(auto & i : matrix){
        for(char & j : i){
            j = '#';
        }
    }
}

void reset_visited(){
    for(auto & i : visited){
        for(bool & j : i){
            j = false;
        }
    }
}

void kill_bad_boys(){
    for(auto location:bad_boys_locations){
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i != 0 && j != 0) continue;
                matrix[location.first+i][location.second+j] = '#';
            }
        }
    }
}

void find_all_good_boys(int x, int y){
    visited[x][y] = true;
    for(int i = -1; i <= 1; i ++){
        for(int j = -1; j <= 1; j++){
            if(i != 0 && j != 0) continue;
            if(matrix[x+i][y+j] != '#' && !visited[x+i][y+j]){
                if(matrix[x+i][y+j] == 'G'){
                    found_good_boys++;
                }
                find_all_good_boys(x+i, y+j);
            }
        }
    }
}

void single_question(){
    cin >> n >> m;
    reset_matrix();
    reset_visited();
    number_of_good_boys = 0;
    found_good_boys = 0;
    bad_boys_locations.clear();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> new_elem;
            matrix[i][j] = new_elem;
            if(new_elem == 'B'){
                bad_boys_locations.emplace_back(i, j);
            }
            else if(new_elem == 'G'){
                number_of_good_boys++;
            }
        }
    }
    kill_bad_boys();
    if(matrix[n][m] != '#'){
        find_all_good_boys(n, m);
    }
    if(number_of_good_boys == found_good_boys){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

void load_data(){
    cin >> t;
    while(t--){
        single_question();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
}