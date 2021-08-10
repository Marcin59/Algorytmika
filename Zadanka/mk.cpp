#include<iostream>
#include<string>

using namespace std;

int main(){
    string str1 = "234";
    string str2 = "567";
    swap(str1[1], str2[1]);
    cout << str1;
}