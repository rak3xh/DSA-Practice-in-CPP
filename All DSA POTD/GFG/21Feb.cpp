#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int n, string &s, int i, int j, bool need, vector<vector<vector<int>>> &dp)
    {
        // the parenthesis at i means just in the lhs of the the ith index
        if (i + 1 == j)
        {
            if (need == false)
            {
                return (s[i] == 'F') ? 1 : 0;
            }
            else
            {
                return (s[i] == 'F') ? 0 : 1;
            }
        }
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j][need] != -1)
        {
            return dp[i][j][need];
        }
        int ans = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            if (s[k] == '^')
            {
                if (need == true)
                {
                    int ct1 = solve(n, s, i, k, true, dp);      // 1
                    int ct2 = solve(n, s, k + 1, j, false, dp); // 1
                    int ct3 = solve(n, s, i, k, false, dp);     // 0
                    int ct4 = solve(n, s, k + 1, j, true, dp);  // 0
                    ans = ans + ct1 * ct2 + ct3 * ct4;
                }
                else
                {
                    int ct1 = solve(n, s, i, k, true, dp);
                    int ct2 = solve(n, s, k + 1, j, true, dp);
                    int ct3 = solve(n, s, i, k, false, dp);
                    int ct4 = solve(n, s, k + 1, j, false, dp);
                    ans = ans + ct1 * ct2 + ct3 * ct4;
                }
            }
            else if (s[k] == '|')
            {
                if (need == true)
                {
                    int ct1 = solve(n, s, i, k, true, dp);
                    int ct2 = solve(n, s, k + 1, j, false, dp);
                    int ct3 = solve(n, s, k + 1, j, true, dp);

                    int ct4 = solve(n, s, i, k, false, dp);
                    int ct5 = solve(n, s, i, k, true, dp);
                    int ct6 = solve(n, s, k + 1, j, true, dp);
                    ans = ans + ct1 * ct2 + ct1 * ct3 + ct6 * ct4;
                }
                else
                {
                    int ct1 = solve(n, s, i, k, false, dp);     // 1
                    int ct2 = solve(n, s, k + 1, j, false, dp); // 1
                    ans = ans + ct1 * ct2;
                }
            }
            else
            {
                if (need == true)
                {
                    int ct1 = solve(n, s, i, k, true, dp);
                    int ct2 = solve(n, s, k + 1, j, true, dp);
                    ans = ans + ct1 * ct2;
                }
                else
                {
                    int ct1 = solve(n, s, i, k, true, dp);
                    int ct2 = solve(n, s, k + 1, j, false, dp);

                    int ct4 = solve(n, s, i, k, false, dp);
                    int ct5 = solve(n, s, k + 1, j, true, dp);
                    ans = ans + ct1 * ct2 + ct4 * ct5 + ct4 * ct2;
                }
            }
        }
        return dp[i][j][need] = (ans % 1003);
    }
    int countWays(int n, string s)
    {
        // code here
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solve(n, s, 0, s.size(), true, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        Solution ob;
        cout << ob.countWays(n, s) << "\n";
    }
    return 0;
}