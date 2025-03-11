#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countWays(int n)
    {
        // your code here
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n + 1; i++)
        {
            int next_stair = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = next_stair;
        }
        return dp[1];
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}
