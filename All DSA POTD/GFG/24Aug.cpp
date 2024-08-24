#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp;
    int fun(int i, int w, vector<int> &wt, vector<int> &val)
    {
        if (i >= wt.size())
        {
            return 0;
        }
        if (dp[i][w] != -1)
        {
            return dp[i][w];
        }
        int ans = 0;
        if (w >= wt[i])
        {
            ans = max(ans, val[i] + fun(i + 1, w - wt[i], wt, val));
        }
        ans = max(ans, fun(i + 1, w, wt, val));
        return dp[i][w] = ans;
    }
    int knapSack(int W, vector<int> &wt, vector<int> &val)
    {
        // Your code here
        dp.resize(wt.size() + 1, vector<int>(W + 1, -1));
        return fun(0, W, wt, val);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number)
        {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number)
        {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number)
        {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}