#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b)
{
    int alice = 0, bob = 0;
    vector<int> score;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            continue;
        }
        else if (b[i] > a[i])
        {
            bob++;
        }
        else
        {
            alice++;
        }
    }
    score.push_back(alice);
    score.push_back(bob);
    return score;
}