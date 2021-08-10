#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<variant>

using namespace std;

class Cow
{
public:
    int n;
    int x;
    int y;
    bool alive;
};

class detention
{
public:
    int n;
    Cow cow_to_dead;
    Cow cow_from_dead;
};

struct by_age {
    bool operator()(detention  &a, detention  &b) const {
        return a.n < b.n;
    }
};

int main()
{
    int cows_number;
    scanf("%i", &cows_number);
    vector<Cow> cowsN;
    vector<Cow> cowsE;
    char direction;
    int x, y;
    for (int i = 0; i<cows_number; i++)
    {
        scanf("\n%c", &direction);
        scanf("%i", &x);
        scanf("%i", &y);
        if (direction == 'E')
        {
            cowsE.emplace_back();
            cowsE.back().x = x;
            cowsE.back().y = y;
            cowsE.back().n = i;
            cowsE.back().alive = true;
        }
        else
        {
            cowsN.emplace_back();
            cowsN.back().x = x;
            cowsN.back().y = y;
            cowsN.back().n = i;
            cowsN.back().alive = true;
        }
    }

    vector<detention> detentions;
    for (auto cowE : cowsE)
    {
        for(auto cowN : cowsN)
        {
            if (cowE.x <= cowN.x && cowE.y >= cowN.y)
            {
                if (cowN.x - cowE.x < cowE.y - cowN.y)
                {
                    detention new_detention{};
                    new_detention.n = cowN.x - cowE.x;
                    new_detention.cow_to_dead = cowE;
                    new_detention.cow_from_dead = cowN;
                    detentions.push_back(new_detention);
                }
                else if (cowN.x - cowE.x > cowE.y - cowN.y)
                {
                    detention new_detention{};
                    new_detention.n = cowE.y - cowN.y;
                    new_detention.cow_to_dead = cowN;
                    new_detention.cow_from_dead = cowE;
                    detentions.push_back(new_detention);
                }
            }
        }
    }
    sort(detentions.begin(), detentions.end(), by_age());
    vector<int> results;
    cout << 34324;
    for(auto item:detentions)
    {
        cout << item.n;
        if (item.cow_from_dead.alive && results[item.cow_to_dead.n] == 0)
        {
            results[item.cow_to_dead.n] = item.n;
            item.cow_to_dead.alive = false;
        }
    }
    cout << 21324;
    for (auto item : results)
    {
        if (item == 0)
        {
            cout << "Infinity";
        }
        else
        {
            cout << item;
        }

        cout << endl;
    }
}