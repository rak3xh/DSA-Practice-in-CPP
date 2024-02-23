#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    map<int, int> mp;
    int maxSum(int n)
    {
        // code here.
        if (n == 1 || n == 0)
            return n;
        if (mp.find(n) != mp.end())
            return mp[n];

        int a = max(maxSum(n / 2), n / 2);
        int b = max(maxSum(n / 3), n / 3);
        int c = max(maxSum(n / 4), n / 4);
        ;

        return mp[n] = max(a + b + c, n);
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
        cout << ob.maxSum(n) << "\n";
    }
    return 0;
}