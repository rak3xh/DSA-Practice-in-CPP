#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int x = 1 + solve(n - 1, dp);
        int y = 1 + solve(n - 2, dp);

        return dp[n] = min(x, y);
    }
    int nthStair(int n)
    {
        //  Code here
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthStair(n);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}