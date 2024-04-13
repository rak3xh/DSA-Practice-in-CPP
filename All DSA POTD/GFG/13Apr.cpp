#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long reversedBits(long long x)
    {
        // code here
        long long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = (x >> i) & 1;
            ans = ans | (static_cast<long long>(bit) << (31 - i));
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
        long long X;

        cin >> X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}