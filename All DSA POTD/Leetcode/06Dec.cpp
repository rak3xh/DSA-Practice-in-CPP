#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        int ans = 0;
        int sum = 0;
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        for (int i = 1; i <= n; ++i)
        {
            if (bannedSet.find(i) == bannedSet.end() && sum + i <= maxSum)
            {
                ++ans;
                sum += i;
            }
        }

        return ans;
    }
};
