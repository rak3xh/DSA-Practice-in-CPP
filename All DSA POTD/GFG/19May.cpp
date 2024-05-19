#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findClosest(int n, int k, int arr[])
    {
        // Complete the function
        int start = 0;
        int end = n - 1;
        int mid;
        int diff = INT_MAX;
        int ans;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (arr[mid] == k)
            {
                return k;
            }
            else if (arr[mid] > k)
            {
                if (diff >= abs(arr[mid] - k))
                {
                    diff = abs(arr[mid] - k);
                    ans = arr[mid];
                }
                end = mid - 1;
            }
            else
            {
                if (diff > abs(k - arr[mid]))
                {
                    diff = abs(k - arr[mid]);
                    ans = arr[mid];
                }
                start = mid + 1;
            }
        }
        return ans;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.findClosest(n, k, arr) << endl;
    }
}
