#include <bits/stdc++.h>
using namespace std;

// C++ 20 Solution using contains

/*
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> seen;

        for (const int a : arr)
        {
            if (seen.contains(a * 2) || a % 2 == 0 && seen.contains(a / 2))
                return true;
            seen.insert(a);
        }

        return false;
    }
};
*/

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> seen;
        for (const int a : arr)
        {
            if (seen.find(a * 2) != seen.end() || (a % 2 == 0 && seen.find(a / 2) != seen.end()))
                return true;
            seen.insert(a);
        }
        return false;
    }
};