#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static const long long MOD = 1000000007;

    int countPartitions(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<long long> dp(n + 1, 0), prefix(n + 1, 0);
        dp[0] = 1;
        prefix[0] = 1;

        deque<int> minq, maxq;
        int j = 0;

        for (int i = 0; i < n; i++)
        {

            // Maintain decreasing max deque
            while (!maxq.empty() && nums[i] > maxq.back())
                maxq.pop_back();
            maxq.push_back(nums[i]);

            // Maintain increasing min deque
            while (!minq.empty() && nums[i] < minq.back())
                minq.pop_back();
            minq.push_back(nums[i]);

            // Shrink window: ensure max - min <= k
            while (!maxq.empty() && !minq.empty() && (maxq.front() - minq.front() > k))
            {
                if (nums[j] == maxq.front())
                    maxq.pop_front();
                if (nums[j] == minq.front())
                    minq.pop_front();
                j++;
            }

            // dp[i+1] = sum(dp[j] ... dp[i])
            long long total = prefix[i];
            long long subtract = (j > 0 ? prefix[j - 1] : 0);

            dp[i + 1] = (total - subtract + MOD) % MOD;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};
