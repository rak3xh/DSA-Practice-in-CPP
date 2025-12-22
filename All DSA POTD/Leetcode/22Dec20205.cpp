#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int k = strs[0].length();

        // dp[i] = length of LIS ending at column i
        vector<int> dp(k, 1);

        for (int i = 1; i < k; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                bool ok = true;
                for (const string &s : strs)
                {
                    if (s[j] > s[i])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int longest = *max_element(dp.begin(), dp.end());
        return k - longest;
    }
};
