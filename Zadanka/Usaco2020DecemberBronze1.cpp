#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<unsigned int> numbers;
    unsigned int new_elem;
    for (int i = 0; i < 7; i++)
    {
        scanf("%u", &new_elem);
        numbers.push_back(new_elem);
    }
    sort(numbers.begin(), numbers.end());
    int A = numbers[0];
    int B = numbers[1];
    int C = numbers[numbers.size()-1] - B - A;
    cout << A << " " << B << " " << C;
}


