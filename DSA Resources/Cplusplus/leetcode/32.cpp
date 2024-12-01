#include <bits/stdc++.h>
using namespace std;

// C++14 Solution
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        string s2 = ")" + s;
        // dp[i] := the length of the longest valid parentheses in the substring
        // s2[1..i]
        vector<int> dp(s2.length(), 0);

        for (int i = 1; i < s2.length(); ++i)
            if (s2[i] == ')' && s2[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;

        return *max_element(dp.begin(), dp.end());
    }
};
// C++20 Solution
/*
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        const string s2 = ")" + s;
        // dp[i] := the length of the longest valid parentheses in the substring
        // s2[1..i]
        vector<int> dp(s2.length());

        for (int i = 1; i < s2.length(); ++i)
            if (s2[i] == ')' && s2[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;

        return ranges::max(dp);
    }
};
*/
