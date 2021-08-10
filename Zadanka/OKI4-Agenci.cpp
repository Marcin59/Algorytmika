#include<iostream>
#include<vector>

using namespace std;

int const cities_number = 255;
int motion_number = 0;
int n, m;
vector<int> graph[cities_number];
bool visited[cities_number][cities_number];
int a1, a2;
int a, b;
vector<pair<int, int>> posible_positions1, posible_positions2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    cin >> a1 >> a2;
    posible_positions1.emplace_back(a1, a2);
    visited[a1][a2] = true;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }

    while(not posible_positions1.empty()){
        while(not posible_positions1.empty()){
            auto data = posible_positions1.back();
            posible_positions1.pop_back();
            if(data.first == data.second){
                cout << motion_number;
                return 0;
            }
            for(auto child: graph[data.first]){
                if(not visited[child][data.second]) {
                    posible_positions2.emplace_back(child, data.second);
                    visited[child][data.second] = true;
                }
            }
        }
        motion_number++;
        while(not posible_positions2.empty()){
            auto data = posible_positions2.back();
            posible_positions2.pop_back();
            for(auto child: graph[data.second]){
                if(not visited[data.first][child]) {
                    posible_positions1.emplace_back(data.first, child);
                    visited[data.first][child] = true;
                }
            }
        }
    }
    cout << "NIE";
}

