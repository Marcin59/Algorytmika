#include<iostream>
#include<map>
#include <algorithm>
#include<vector>

using namespace std;
const unsigned int PAIR_WEIGHT_LIMIT = 1<<31;
unsigned int finding_sum = PAIR_WEIGHT_LIMIT;
map<int, int> pair_elements;
map<int, int> not_pair_elements;
vector<int> elements;
int n;
int new_elem;
int number_of_zeros;
int result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--){
        cin >> new_elem;
        if(new_elem == 0){
            number_of_zeros++;
        }
        else{
            if(not_pair_elements[new_elem] == 0){
                elements.push_back(new_elem);
            }
            not_pair_elements[new_elem]++;
        }
    }
    sort(elements.begin(), elements.end());
    unsigned int finding_number;
    int new_pairs;
    for(int i = elements.size()-1; i >= 0; i--){
        while(finding_sum/2 > elements[i]){
            finding_sum /= 2;
        }
        finding_number = finding_sum - elements[i];
        if(elements[i] != finding_number) {
            new_pairs = min(not_pair_elements[elements[i]], not_pair_elements[finding_number]);
            not_pair_elements[elements[i]] -= new_pairs;
            not_pair_elements[finding_number] -= new_pairs;
            pair_elements[elements[i]] += new_pairs;
            pair_elements[finding_number] += new_pairs;
            result += new_pairs;
        }
        else{
            new_pairs = not_pair_elements[finding_number]/2*2;
            not_pair_elements[finding_number] -= new_pairs;
            pair_elements[elements[i]] += new_pairs;
            result += new_pairs/2;
        }
    }
//
//    cout << "Not paired elements:" << endl;
//    for(auto item:not_pair_elements){
//        cout << item.first << ' ' << item.second << endl;
//    }
//    cout << endl;
//
//    cout << "Paired elements:" << endl;
//    for(auto item:pair_elements){
//        cout << item.first << ' ' << item.second << endl;
//    }
//    cout << endl;
//
//    cout << "Number of zeros: " << number_of_zeros << endl << endl;

    for(unsigned long long i = 1; i < PAIR_WEIGHT_LIMIT; i *= 2){
        if(!number_of_zeros){
            break;
        }
        if(not_pair_elements[i]){
            new_pairs = min(not_pair_elements[i], number_of_zeros);
//            cout << "Number of new pairs: " << new_pairs << "   from: " <<  i << endl;
            result += new_pairs;
            number_of_zeros -= new_pairs;
        }
    }
//    cout << endl;

    for(unsigned long long i = 1; i < PAIR_WEIGHT_LIMIT; i *= 2){
        if(number_of_zeros < 2){
            break;
        }
        if(pair_elements[i]/2){
            new_pairs = min(pair_elements[i]/2*2, number_of_zeros/2*2);
            result += new_pairs/2;
            number_of_zeros -= new_pairs;
        }
    }
    cout << result;
}