#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> vis;
            int cnt[2] = {0, 0};

            for (int j = i; j < n; ++j)
            {
                // C++14 replacement for vis.contains(nums[j])
                if (vis.find(nums[j]) == vis.end())
                {
                    vis.insert(nums[j]);
                    ++cnt[nums[j] & 1];
                }

                if (cnt[0] == cnt[1])
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
