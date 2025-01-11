#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minOperation(int n)
    {
        // code here.
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 1)
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
            }
        }
        return dp[n];
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
        Solution ob;
        cout << ob.minOperation(n) << endl;

        cout << "~"
             << "\n";
    }
}