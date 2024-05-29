#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findWinner(int n, int x, int y)
    {
        // code here
        if (x % 2 && y % 2)
            return n % 2;
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            bool win = !dp[i - 1];
            if (i >= x)
                win |= !dp[i - x];
            if (i >= y)
                win |= !dp[i - y];
            dp[i] = win;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}
