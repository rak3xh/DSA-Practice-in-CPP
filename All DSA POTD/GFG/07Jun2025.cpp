#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2)
    {
        // Code here.
        int n = min(a1.size(), a2.size());
        map<int, int> mp;
        int ans = 0, sum = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += a1[i] - a2[i];
            if (mp.count(sum))
            {
                ans = max(ans, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return ans;
    }
};