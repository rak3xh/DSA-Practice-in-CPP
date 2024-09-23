#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        const int n = s.length();
        const unordered_set<string> dictionarySet{dictionary.begin(), dictionary.end()};
        // dp[i] := the minimum extra letters if breaking up s[0..i) optimally
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // s[j..i) is in `dictionarySet`.
                if (dictionarySet.find(s.substr(j, i - j)) != dictionarySet.end())
                {
                    dp[i] = min(dp[i], dp[j]);
                }
                // s[j..i) are extra letters.
                else
                {
                    dp[i] = min(dp[i], dp[j] + i - j);
                }
            }
        }

        return dp[n];
    }
};
