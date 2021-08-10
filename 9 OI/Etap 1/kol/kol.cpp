#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

bool check_places(vector<int> &arr, int s, int e, int p)
    for (int i = s; i < e ; i++)
    {
        if (p > arr[i])
        {
            return false;
        }
    }
    return true;
}

void accept_injury(vector<int> &arr, int s, int e, int p)
{
    for (int i = s; i < e ; i++)
    {
        arr[i] -= p;
    }
}

main()
{
    int cities, places_number, injuries_number;
    vector<int> places;

    scanf("%i", &cities);
    scanf("%i", &places_number);
    scanf("%i", &injuries_number);

    places.assign(cities, places_number);
    
    int start_index, end_index, needed_places;

    for(int i = 0; i < injuries_number; i++)
    {
        scanf("%i", &start_index);
        scanf("%i", &end_index);
        scanf("%i", &needed_places);

        if (check_places(places, start_index-1, end_index-1, needed_places))
        {
            accept_injury(places, start_index-1, end_index-1, needed_places);
            cout << "T" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
        
    }
    
}