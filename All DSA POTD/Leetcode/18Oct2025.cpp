#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        int ans = 0;
        int occupied = INT_MIN;

        sort(nums.begin(), nums.end());

        for (const int num : nums)
            if (occupied < num + k)
            {
                occupied = max(occupied + 1, num - k);
                ++ans;
            }

        return ans;
    }
};