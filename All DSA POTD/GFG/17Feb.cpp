#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int t1 = (n - 1) / 2, t2 = (n / 2);
        if (n % 2 == 0)
        {
            t1 = (n / 2);
        }
        for (int i = 0; i < t1; i++)
        {
            if (arr[i] < arr[(2 * i) + 1])
            {
                return false;
            }
            if (i < t2 && arr[i] < arr[2 * (i + 1)])
            {
                return false;
            }
        }
        return true;
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
        int a[4 * n] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.isMaxHeap(a, n) << endl;
    }
    return 0;
}