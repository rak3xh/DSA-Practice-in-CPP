#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        int jumps = 1, farthest = arr[0], currentEnd = arr[0];

        if (n <= 1)
            return 0;

        if (arr[0] == 0)
            return -1;

        // if(n > )

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jumps;

            farthest = max(farthest, arr[i] + i);

            if (i == currentEnd)
            {
                jumps++;
                currentEnd = farthest;

                if (currentEnd <= i)
                    return -1;
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
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
