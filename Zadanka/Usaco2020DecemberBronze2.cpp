#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

struct ThePetals
{
    int value = 0;
};

int main()
{
    vector<int> numbers;
    int new_elem;
    int n;
    int result;
    scanf("%u", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &new_elem);
        numbers.push_back(new_elem);
    }
    int the_sum;
    float average;
    for(int i = 0; i < n; i++)
    {
        map<float, ThePetals> petals;
        the_sum = 0;
        average = 0;
        for (int j = i; j < n; j++)
        {
            petals[numbers[j]].value += 1;
            the_sum += numbers[j];
            average = (float)the_sum/(j-i+1);
            if (petals[average].value > 0)
            {
                result++;
            }
        }
    }
    cout << result;
}
