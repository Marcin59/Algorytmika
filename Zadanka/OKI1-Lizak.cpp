#include<iostream>

using namespace std;
const int M=2e6+7;
pair<int, int> results[M];
string lolipop;

void short_the_chain(int start, int end,int actual_price)
{
    if(start <= end)
    {
        results[actual_price].first = start;
        results[actual_price].second = end;
        if (lolipop[start-1] == lolipop[end-1] && lolipop[end-1] == 'W')
        {
            start++;
            end--;
        }
        else if (lolipop[start-1] == 'T')
        {
            start++;
        }
        else
        {
            end--;
        }
        actual_price -= 2;
        short_the_chain(start, end, actual_price);
    }
}

int main()
{
    int T_left = 0;
    bool T_left_count_or_not = true;
    int T_right = 0;
    int n;
    int lolipop_price = 0;
    int injuries;
    scanf("%i", &n);
    scanf("%i", &injuries);
    cin >> lolipop;
    for(int i = 0; i < n; i++)
    {
        T_right++;
        if (lolipop[i] == 'W')
        {
            T_left_count_or_not = false;
            T_right = 0;
            lolipop_price++;
        }
        else
        {
            lolipop_price += 2;
        }
        if (T_left_count_or_not)
        {
            T_left++;
        }
    }
    int start = 1;
    int end = n;
    short_the_chain(start, end, lolipop_price);
    if (T_left < T_right)
    {
        lolipop_price -= T_left*2+1;
        start = T_left+2;
    }
    else
    {
        lolipop_price -= T_right*2+1;
        end -= T_right+1;
    }
    short_the_chain(start, end, lolipop_price);
    int question;
    for (int i = 0; i < injuries; i++) {
        scanf("%i", &question);
        if (results[question].first != 0) {
            printf("%i %i\n", results[question].first, results[question].second);
        }
        else
        {
            cout << "NIE" << endl;
        }
    }
}

