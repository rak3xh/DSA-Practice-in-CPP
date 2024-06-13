#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int padovanSequence(int n)
    {
        // code here.
        vector<int> f(n + 3, -1);

        f[0] = 1;
        f[1] = 1;
        f[2] = 1;
        int mod = 1000000007;
        for (int i = 3; i <= n; i++)
        {

            f[i] = (f[i - 2] + f[i - 3]) % mod;
        }
        return f[n];
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}