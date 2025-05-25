#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        // code here
        map<int, int> mp;
        sort(arr.begin(), arr.end());
        for (auto i : arr)
        {
            for (int j = 1; j <= i; j++)
            {
                if (mp.count(j * j) and mp.count(i * i - j * j))
                {
                    return 1;
                }
            }
            mp[i * i] = 1;
        }
        return 0;
    }
};