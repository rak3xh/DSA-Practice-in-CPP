
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        // Your code here
        int MAX = 0;
        int i = 0, j = n - 1;
        while (i < n)
        {
            if (a[i] <= a[j])
            {
                MAX = max(MAX, j - i);
                j = n - 1;
                i++;
            }
            else
            {
                j--;
            }
        }
        return MAX;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}