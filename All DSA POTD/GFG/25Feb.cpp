#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Complete this function
    vector<int> arr = {3, 5, 10};
    long long int dp[100001][3];
    long long int traverse(long long int n, int i)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (i == 3)
            return 0;

        if (dp[n][i] != -1)
            return dp[n][i];

        int ans = traverse(n - arr[i], i);
        ans += traverse(n, i + 1);

        return dp[n][i] = ans;
    }
    long long int count(long long int n)
    {
        // Your code here
        memset(dp, -1, sizeof(dp));
        return traverse(n, 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        Solution obj;
        cout << obj.count(n) << endl;
    }
    return 0;
}