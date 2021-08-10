#include<iostream>
#include<vector>
using namespace std;

void check_injury()
{
    int poops_number;
    scanf("%i", &poops_number);
    vector<int> poops(poops_number);
    scanf("%i", &poops[0]);
    int posibilities, the_sum;
    posibilities = 0;

    for (int i = 1; i<poops_number; i++)
    {
        scanf("%i", &poops[i]);
        if (poops[i-1]+1 < poops[i])
        {
            posibilities++;
            the_sum = poops[i-1] + poops[i];
            poops[i] = the_sum/2;
            if (the_sum%2 == 1)
            {
                poops[i] = poops[i] * 2 + 1;
            }
        }
    }
    if (posibilities%2 == 0)
    {
        cout << "NIE" << endl;
    }
    else
    {
        cout << "TAK" << endl;
    }
}

main()
{
    int injuries_number;
    scanf("%i", &injuries_number);
    for (int i = 0; i < injuries_number; i++)
    {
        check_injury();
    }
}