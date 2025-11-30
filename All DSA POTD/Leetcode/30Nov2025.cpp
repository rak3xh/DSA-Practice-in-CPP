#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        long sum = accumulate(nums.begin(), nums.end(), 0LL); // Use 0LL for long long type
        int remainder = sum % p;
        if (remainder == 0)
            return 0;

        unordered_map<int, int> prefixToIndex{{0, -1}};
        int ans = nums.size();
        int prefix = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - remainder + p) % p;
            if (prefixToIndex.find(target) != prefixToIndex.end())
            {
                ans = min(ans, i - prefixToIndex[target]);
            }
            prefixToIndex[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};