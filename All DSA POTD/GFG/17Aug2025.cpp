#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rearrange(vector<int> &arr, int x)
    {
        // code here
        map<int, vector<int>> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            mp[abs(arr[i] - x)].push_back(arr[i]);
        }

        int i = 0;

        // dont confuse this as O(N*N) actually total elements we will have is O(N) and we are traversing them only.

        for (auto it : mp)
        {
            for (auto itr : it.second)
            {
                arr[i] = itr;
                i++;
            }
        }
    }
};