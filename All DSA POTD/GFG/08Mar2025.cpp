#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string longestPalindrome(string &s)
    {
        // code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();
        string ans = "";
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxi = 0;
        int end = 0;
        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == rev[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    int k = n - j;
                    // cout<<k;
                    //<<dp[i][j]-1+k<<endl;
                    if (k + dp[i][j] - 1 == i - 1)
                    {
                        if (dp[i][j] > maxi)
                        {
                            maxi = dp[i][j];
                            end = i - 1;
                        }
                    }
                }
            }
        }
        return s.substr(end - maxi + 1, maxi);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}
