#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(vector<int> &arr, vector<int> &cost)
    {
        // code here
        int n = cost.size();
        int start = INT_MAX;
        int end = INT_MIN;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (start > arr[i])
                start = arr[i];
            if (end < arr[i])
                end = arr[i];
        }

        while (start <= end)
        {

            int mid = start + ((end - start) / 2);

            int cost1 = 0;
            int cost2 = 0;

            for (int i = 0; i < n; i++)
            {
                cost1 += (abs(arr[i] - mid) * cost[i]);
                cost2 += (abs(arr[i] - (mid + 1)) * cost[i]);
            }

            if (cost1 < cost2)
            {
                ans = cost1;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};
