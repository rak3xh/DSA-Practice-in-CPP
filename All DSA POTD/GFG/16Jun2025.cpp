#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(vector<int> &heights, vector<int> &cost)
    {
        // code here
        int n = heights.size();
        long long res = LLONG_MAX;
        int r = *max_element(begin(heights), end(heights));
        for (int mid = 1; mid <= r; mid++)
        {
            long long spent = 0;
            for (int i = 0; i < n; i++)
            {
                spent += (abs(heights[i] - mid) * cost[i]);
            }
            res = min(res, spent);
        }
        return res;
    }
};
