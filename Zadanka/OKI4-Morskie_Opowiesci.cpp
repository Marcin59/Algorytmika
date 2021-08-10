#include<iostream>
#include<vector>

using namespace std;

const int M = 5e3+4;
vector<int> graph[M];
int index = 0;
int n, m, k;
int a, b;
int s, t, d;
vector<int> Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    string result;
    while(k--){
        index++;
        result = "NIE";
        cin >> s >> t >> d;
        Q.clear();
        Q.push_back(s);
        int count = 0;
        while(not Q.empty()){
            int l = Q.size();
            for(int i = 0; i < l; i++){
                auto data = Q.back();
                if(data == t && count <= d && !(count - d)%2){
                    result = "TAK";
                    d = 0;
                    break;
                }
                Q.pop_back();
                for(auto child:graph[data]){
                    //cout << data << "==>" << child << endl;
                    Q.insert(Q.begin(), child);
                }
            }
            count++;
            if(count > d){
                break;
            }
        }
        cout << result << endl;
    }
}
