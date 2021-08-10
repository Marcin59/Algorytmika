#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>

using namespace std;
map<string, int> calendar_years;
int n;
unordered_map<string, string> cows_years;
unordered_map<string, vector<pair<string, string>>> graph;
int result;

void load_data(){
    cin >> n;
    string cow, state, calendar_year, to_cow;
    string born, in, year, from;
    while(n--){
        cin >> cow >> born >> in >> state >> calendar_year >> year >> from >> to_cow;
        cows_years[cow] = calendar_year;
        graph[to_cow].push_back({cow, state});
    }
}

void dfs(string node_cow, int actual_sum){
    if(node_cow == "Elsie"){
        result = actual_sum;
    }
    for(auto child_cow:graph[node_cow]){
        if(child_cow.second == "previous"){
            if(calendar_years[cows_years[node_cow]] > calendar_years[cows_years[child_cow.first]]){
                dfs(child_cow.first, actual_sum + (calendar_years[cows_years[node_cow]] - calendar_years[cows_years[child_cow.first]]));
            }
            else{
                dfs(child_cow.first, actual_sum + (calendar_years[cows_years[node_cow]] - calendar_years[cows_years[child_cow.first]])+12);
            }
        }
        else{
            if(calendar_years[cows_years[child_cow.first]] <= calendar_years[cows_years[node_cow]]){
                dfs(child_cow.first, actual_sum - ((calendar_years[cows_years[child_cow.first]] - calendar_years[cows_years[node_cow]])+12));
            }
            else{
                dfs(child_cow.first, actual_sum - (calendar_years[cows_years[child_cow.first]] - calendar_years[cows_years[node_cow]]));
            }
        }
    }
}

void print_result(){
    dfs("Bessie", 0);
    cout << abs(result);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    calendar_years["Ox"] = 1;
    calendar_years["Tiger"] = 2;
    calendar_years["Rabbit"] = 3;
    calendar_years["Dragon"] = 4;
    calendar_years["Snake"] = 5;
    calendar_years["Horse"] = 6;
    calendar_years["Goat"] = 7;
    calendar_years["Monkey"] = 8;
    calendar_years["Rooster"] = 9;
    calendar_years["Dog"] = 10;
    calendar_years["Pig"] = 11;
    calendar_years["Rat"] = 12;
    cows_years["Bessie"] = "Ox";
    load_data();
    print_result();
}