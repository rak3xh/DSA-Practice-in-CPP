#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
private:
    int firstOccurence(int arr[], int n, int x)
    {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (arr[mid] == x)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (x > arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
    int lastOccurence(int arr[], int n, int x)
    {
        int s = 0;
        int e = n - 1;
        int ans = -1;
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (arr[mid] == x)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (x > arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // code here
        // the total number of occurrence because it is a sorted array
        // will be last Occurence - First Occurence +1
        int first = firstOccurence(arr, n, x);
        int last = lastOccurence(arr, n, x);
        if (first == -1 && last == -1)
        {
            return 0;
        }
        else
        {
            return last - first + 1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}