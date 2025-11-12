#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        // count how many 1s are present
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0)
            return n - ones;

        // the minimum operations to make the shortest subarray with gcd == 1
        int minOps = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j)
            {
                g = __gcd(g, nums[j]);
                if (g == 1)
                { // gcd(nums[i..j]) == 1
                    minOps = min(minOps, j - i);
                    break;
                }
            }
        }

        // After making the shortest subarray with `minOps`, need additional n - 1
        // operations to make the other numbers 1.
        return minOps == INT_MAX ? -1 : minOps + n - 1;
    }
};
