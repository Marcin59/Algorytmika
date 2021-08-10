#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

int const N_LIMIT = 1e5 + 3;

using namespace std;
int n, m, k, a, b;
vector<int> BKP_graph[N_LIMIT];
vector<int> BLL_graph[N_LIMIT];
int fastest_way[N_LIMIT];
int first_node, second_node;

int main(){
    cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < m; ++i) {
        cin >> first_node >> second_node;
        BKP_graph[first_node].push_back(second_node);
        BKP_graph[second_node].push_back(first_node);
    }
    for(int i = 1; i <= n; i++){
        for(auto child1: BKP_graph[i]){
            for(auto child2: BKP_graph[child1]){
                bool BLL_race = true;
                if(child2 == i){
                    continue;
                }
                for(auto child3:BKP_graph[child2]){
                    if(child3 == i){
                        BLL_race = false;
                    }
                }
//                cout << "BLL_race: " << BLL_race << endl;
//                cout <<"i:  "<<  i << "  child1: "<< child1 << "  child2: " << child2 << endl;
                if(BLL_race){
                    BLL_graph[i].push_back(child2);
                }
            }
        }
    }


    for(int i = 1; i <= n; i++){
        for(auto child:BLL_graph[i]){
            cout << child << ' ';
        }
        cout << endl;
    }
}