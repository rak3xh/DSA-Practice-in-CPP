#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();
        int maxProd = INT_MIN;

        int leftToRight = 1;
        int rightToLeft = 1;
        for (int i = 0; i < n; i++)
        {
            if (leftToRight == 0)
                leftToRight = 1;
            if (rightToLeft == 0)
                rightToLeft = 1;

            leftToRight *= arr[i];
            int j = n - i - 1;
            rightToLeft *= arr[j];
            maxProd = max({leftToRight, rightToLeft, maxProd});
        }
        return maxProd;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}