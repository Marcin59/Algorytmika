#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<climits>

using namespace std;

int const STOPS_LIMIT = 1e3+3;
map<int, vector<pair<int, vector<int>>>> graph; //way from stop a to b with weight and frequency
int n, k, start_stop, end_stop, start_hour, start_minute;
int stops_number, frequency;
vector<int> stops;
vector<int> weights;
int new_stop;
int new_weight;
int fastest_way[STOPS_LIMIT];
queue<int> the_queue;

void load_data(){
    cin >> n >> k >> start_stop >> end_stop >> start_hour >> start_minute;
    int i = k;
    int actual_distance_from_start;
    int actual_distance_from_end;
    while(i--){
        actual_distance_from_start = 0;
        cin >> stops_number >> frequency;
        stops.clear();
        for(int j = 0; j < stops_number; j++){
            cin >> new_stop;
            stops.push_back(new_stop);
        }
        weights.clear();
        for(int j = 0; j < stops_number-1; j++){
            cin >> new_weight;
            weights.push_back(new_weight);
            graph[stops[j]].push_back({stops[j+1], {new_weight, frequency, actual_distance_from_start%frequency}});
            actual_distance_from_start += new_weight;
        }
        actual_distance_from_end = 0;
        for(int j = stops_number-2; j >= 0; j--){
            graph[stops[j+1]].push_back({stops[j], {weights[j], frequency, actual_distance_from_end%frequency}});
            actual_distance_from_end += weights[j];
        }

    }
//    for(auto item:graph){
//        cout << "Node: " << item.first << endl;
//        for(auto a:item.second){
//            cout << "Child: " << a.first << "   Weight: " << a.second[0] << "  Frequency: " << a.second[1] << "   Distance_from_start: " << a.second[2] << endl;
//        }
//        cout << endl;
//    }
}

void find_fastest_way(){
    for(int i = 0; i <= n; i++){
        fastest_way[i] = INT_MAX;
    }
    fastest_way[start_stop] = start_minute;
    the_queue.push(start_stop);
    int node;
    int child_node, child_weight, child_frequency, child_actual_distance;
    while(!the_queue.empty()){
        node = the_queue.front();
        the_queue.pop();
        for(const auto& child:graph[node]){
            child_node = child.first;
            child_weight = child.second[0];
            child_frequency = child.second[1];
            child_actual_distance = child.second[2];
//            cout << "Fastest way to " << child_node << " = " << fastest_way[node] + child_weight + (child_frequency-(fastest_way[node] - child_actual_distance)%child_frequency)%child_frequency<< endl;
            if(fastest_way[child_node] > fastest_way[node] + child_weight + (child_frequency-(fastest_way[node] - child_actual_distance)%child_frequency)%child_frequency){
                fastest_way[child_node] = fastest_way[node] + child_weight + (child_frequency-(fastest_way[node] - child_actual_distance)%child_frequency)%child_frequency;
                the_queue.push(child_node);
            }
        }
    }
}

void print_result(){
    int time = fastest_way[end_stop]-start_minute + start_hour*60 + start_minute;
    int hour, minute;
    hour = (time/60)%24;
    minute = time%60;
    cout << hour << ' ' << minute;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    load_data();
    find_fastest_way();
    print_result();
}