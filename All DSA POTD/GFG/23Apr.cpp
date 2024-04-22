#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int firstElement(int n)
    {
        // code here
        int mod = 1e9 + 7;
        if (n == 1 || n == 2)
            return 1;
        int n1 = 1, n2 = 1;
        int curr = 0;
        for (int i = 2; i <= n; i++)
        {
            curr = n2 + n1;
            curr %= mod;
            n1 = n2 % mod;
            n2 = curr % mod;
        }
        return n1 % mod;
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
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}
