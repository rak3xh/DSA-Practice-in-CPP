#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        // Your code here
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] >= arr[mid - 1] and arr[mid] >= arr[mid + 1] and mid > 0 and mid < n - 1)
            {
                return mid;
            }
            if (arr[mid] >= arr[mid - 1] and mid == n - 1)
                return mid;
            if (arr[mid] >= arr[mid + 1] and mid == 0)
                return mid;
            else if (arr[mid + 1] > arr[mid] and mid < n - 1)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
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
        int a[n], tmp[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tmp[i] = a[i];
        }
        bool f = 0;
        Solution ob;

        int A = ob.peakElement(tmp, n);

        if (A < 0 and A >= n)
            cout << 0 << endl;
        else
        {
            if (n == 1 and A == 0)
                f = 1;
            else if (A == 0 and a[0] >= a[1])
                f = 1;
            else if (A == n - 1 and a[n - 1] >= a[n - 2])
                f = 1;
            else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
                f = 1;
            else
                f = 0;
            cout << f << endl;
        }
    }

    return 0;
}