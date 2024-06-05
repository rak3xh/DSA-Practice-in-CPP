#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        // Your code goes here
        unordered_map<int, int> mp;
        int ans = -1;
        int sum1(0), sum2(0);
        for (int i = 0; i < m; i++)
        {
            int it = b[i];
            sum2 += it;
            mp[it]++;
        }
        for (int i = 0; i < n; i++)
            sum1 += a[i];

        int sum = (sum1 + sum2);
        if (sum % 2 == 0)
        {
            sum = sum / 2;
            int diff = sum - sum1;
            for (int i = 0; i < n; i++)
            {
                if (mp.find(a[i] + diff) != mp.end())
                    return 1;
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
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}