#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int maxValidElements = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {

            int rightBoundary = n;

            if (1LL * nums[i] * k <= nums[n - 1])
            {
                rightBoundary = upper_bound(nums.begin(), nums.end(), 1LL * nums[i] * k) - nums.begin();
            }

            maxValidElements = max(maxValidElements, rightBoundary - i);
        }
        return n - maxValidElements;
    }
};