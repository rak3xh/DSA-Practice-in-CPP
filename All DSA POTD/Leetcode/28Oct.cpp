#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        // Remove duplicate elements
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());

        // Find the maximum number in the array
        int maxNum = *max_element(nums.begin(), nums.end());

        // dp[i] := the longest square streak starting with i
        vector<int> dp(maxNum + 1, 0);

        for (const int num : nums)
        {
            dp[num] = 1; // Initialize current number with streak length 1
            long long squaredNum = static_cast<long long>(num) * num;
            if (squaredNum <= maxNum)
                dp[num] += dp[squaredNum]; // Add the streak of squared number if it exists
        }

        int ans = *max_element(dp.begin(), dp.end()); // Find the maximum streak length
        return ans < 2 ? -1 : ans;                    // If the longest streak is less than 2, return -1
    }
};