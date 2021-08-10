#include<iostream>
#include<vector>

using namespace std;
vector<int> heights;
int n;
int height, width;
int result = 0;

int main(){
    cin >> n;
    while(n--){
        cin >> width >> height;
        while(!heights.empty() && heights.back() > height){
            result++;
            heights.pop_back();
        }
        if(heights.empty() || heights.back() != height){
            heights.push_back(height);
        }
    }
    result += heights.size();
    cout << result;
}