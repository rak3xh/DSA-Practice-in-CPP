#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int mod = 1000000007;
    long long sequence(int n)
    {
        // code here
        long long ans = 0;
        long long cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            long long x = 1;
            for (int j = 0; j < i; j++)
            {
                x *= cnt;
                x %= mod;
                cnt++;
            }
            ans += x;
            ans %= mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.sequence(N) << endl;
    }
    return 0;
}