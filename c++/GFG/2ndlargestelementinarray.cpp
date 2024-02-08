#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n)
    {
        // code here
        int maxi = *max_element(arr, arr + n);
        int mini = *min_element(arr, arr + n);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mini && arr[i] < maxi)
            {
                mini = arr[i];
            }
        }

        if (maxi == mini)
            return -1;
        return mini;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}