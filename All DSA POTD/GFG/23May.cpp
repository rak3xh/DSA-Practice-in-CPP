
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // code here
    vector<vector<int>> memo;
    int minDeletions(int l, int r, const string &str)
    {

        if (l >= r)
        {
            return 0;
        }
        if (memo[l][r] != -1)
        {
            return memo[l][r];
        }
        if (str[l] == str[r])
        {
            memo[l][r] = minDeletions(l + 1, r - 1, str);
        }
        else
        {
            memo[l][r] = 1 + min(minDeletions(l + 1, r, str), minDeletions(l, r - 1, str));
        }
        return memo[l][r];
    }
    int kPalindrome(string str, int n, int k)
    {
        memo.resize(n, vector<int>(n, -1));
        return minDeletions(0, n - 1, str) <= k;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        Solution ob;
        cout << ob.kPalindrome(str, n, k) << endl;
    }
    return 0;
}