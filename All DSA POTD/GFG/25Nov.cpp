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
        int preProd = 1, postProd = 1;
        int maxi = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (preProd == 0)
                preProd = 1;
            if (postProd == 0)
                postProd = 1;

            preProd *= arr[i];
            postProd *= arr[n - i - 1];

            maxi = max(maxi, max(preProd, postProd));
        }
        return maxi;
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