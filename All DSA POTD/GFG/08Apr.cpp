#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find the maximum possible amount of money we can win.
class Solution
{
private:
    long long recursive(int i, int j, int arr[])
    {
        if (i > j)
            return 0;

        int left = arr[i], right = arr[j];

        left += min(recursive(i + 2, j, arr), recursive(i + 1, j - 1, arr));
        right += min(recursive(i + 1, j - 1, arr), recursive(i, j - 2, arr));

        return max(left, right);
    }

    long long memo(int i, int j, int arr[], vector<vector<long long>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        long long left = arr[i], right = arr[j];

        left += min(memo(i + 2, j, arr, dp), memo(i + 1, j - 1, arr, dp));
        right += min(memo(i + 1, j - 1, arr, dp), memo(i, j - 2, arr, dp));

        return dp[i][j] = max(left, right);
    }

public:
    long long maximumAmount(int n, int arr[])
    {
        // Your code here
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        return memo(0, n - 1, arr, dp);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximumAmount(n, a) << endl;
    }
    return 0;
}