#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {

        // Your code here
        int k = 1;
        int gc = (k << 31) & n;
        for (int i = 30; i >= 0; i--)
        {
            int a = ((k << (i + 1)) & gc), b = ((k << i) & n);
            if ((!a && b) || (a && !b))
                gc = gc | (k << i);
        }
        return gc;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t, n;
    cin >> t; // testcases
    while (t--)
    {
        cin >> n; // initializing n

        Solution ob;
        // calling function grayToBinary()
        cout << ob.grayToBinary(n) << endl;
    }
}
