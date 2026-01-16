#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMen(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1)
            {
                int l = max(0, i - arr[i]);
                int r = min(n - 1, i + arr[i]);
                dp[l] = max(dp[l], r);
            }
        }
        if (dp[0] == -1)
            return -1;
        int cur = 0, maxRange = 0, c = 0, p = 0;
        while (cur < n)
        {
            while (c <= cur && c < n)
            {
                maxRange = max(maxRange, dp[c]);
                c++;
            }
            if (maxRange < cur)
                return -1;
            p++;
            cur = maxRange + 1;
        }
        return p;
    }
};