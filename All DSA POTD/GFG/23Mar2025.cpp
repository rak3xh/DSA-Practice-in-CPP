#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int f(int i, string &s, int n, vector<int> &dp)
    {
        if (i >= s.size())
            return 1;

        if (dp[i] != -1)
            return dp[i];

        int curr = s[i] - '0';
        if (curr == 0)
            return 0;

        int one = f(i + 1, s, n, dp);
        int two = 0;

        if (i + 1 < n)
        {
            curr = curr * 10 + (s[i + 1] - '0');

            if (curr <= 26)
            {
                two = f(i + 2, s, n, dp);
            }
        }
        return dp[i] = one + two;
    }
    int countWays(string &digits)
    {
        // Code here
        int n = digits.size();
        vector<int> dp(n, -1);

        return f(0, digits, n, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--)
    {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}