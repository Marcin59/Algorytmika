#include<iostream>
#include<vector>
#include<map>

using namespace std;
template <typename T>

void print_vector(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "";
    }
    cout << endl;
}

main()
{
    int letters_number;
    scanf("%i", &letters_number);
    vector<char> word(letters_number);
    scanf("%c");
    map<char, vector<int>> uccurrence;

    for (int i = 0; i < letters_number; i++)
    {
        scanf("%c", &word[i]);
        uccurrence[word[i]].push_back(i);
    }
    print_vector(word);
    print_vector(uccurrence['a']);
    for (auto item : uccurrence)
    {
        cout << item.first << ": ";
        print_vector(item.second);
    }
}