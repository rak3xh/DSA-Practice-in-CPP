#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int findMaxSum(vector<int> &arr)
    {
        // Your code here
        if (arr.empty())
            return 0;

        if (arr.size() == 1)
            return arr[0];

        vector<int> dp(arr.size());
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < arr.size(); ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }
        return dp.back();
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        // calling function findMaxSum()
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
