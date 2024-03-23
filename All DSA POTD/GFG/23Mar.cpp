#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> Series(int n)
    {
        // Code here
        int mod = 1e9 + 7;
        vector<int> v(n + 1, 0);
        v[0] = 0;
        v[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            v[i] = (v[i - 1] + v[i - 2]) % mod;
        }
        return v;
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
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}