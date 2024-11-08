#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        const int mx = (1 << maximumBit) - 1;
        vector<int> ans;
        int xors = 0;

        for (const int num : nums)
        {
            xors ^= num;
            ans.push_back(xors ^ mx);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};