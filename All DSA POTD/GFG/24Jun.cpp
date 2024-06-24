#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long sumMatrix(long long n, long long q)
    {
        // code here
        return max((long long)0, n - abs(n + 1 - q));
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, q;

        cin >> n >> q;

        Solution ob;
        cout << ob.sumMatrix(n, q) << endl;
    }
    return 0;
}