
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int countMin(string str)
    {
        // complete the function here
        int n = str.size();
        string a = str, b = str;
        reverse(b.begin(), b.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
            dp[0][i] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n] / 2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}
