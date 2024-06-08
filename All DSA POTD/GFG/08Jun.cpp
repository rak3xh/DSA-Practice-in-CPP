#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findExtra(int n, int arr1[], int arr2[])
    {
        // add code here.
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr1[mid] == arr2[mid])
            {
                low = mid + 1;
            }
            else
            {
                if (arr1[mid] == arr2[mid - 1])
                {
                    high = mid - 1;
                }
                else
                {
                    return mid;
                }
            }
        }
        // The loop should return before this point, but in case of an error, return -1.
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
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}