#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        vector<int> l = lengthOfLIS(nums);
        vector<int> r = reverseAndComputeLIS(nums);
        int maxMountainSeq = 0;

        for (int i = 0; i < nums.size(); ++i)
            if (l[i] > 1 && r[i] > 1)
                maxMountainSeq = max(maxMountainSeq, l[i] + r[i] - 1);

        return nums.size() - maxMountainSeq;
    }

private:
    // Helper to calculate the LIS ending at each position
    vector<int> lengthOfLIS(const vector<int> &nums)
    {
        vector<int> tails;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end())
                tails.push_back(num);
            else
                *it = num;
            dp[i] = tails.size();
        }
        return dp;
    }

    // Helper to calculate LIS for reversed array
    vector<int> reverseAndComputeLIS(const vector<int> &nums)
    {
        vector<int> reversedNums(nums.rbegin(), nums.rend());
        vector<int> reversedLIS = lengthOfLIS(reversedNums);
        reverse(reversedLIS.begin(), reversedLIS.end());
        return reversedLIS;
    }
};
