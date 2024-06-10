#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        // code here
        unordered_map<char, int> mp;
        char a[] = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};

        for (int i = 0; i < 9; i++)
        {
            mp[a[i]] = i;
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = mp[nuts[i]];
        }

        sort(v.begin(), v.end());

        vector<int> v1(n);

        for (int i = 0; i < n; i++)
        {
            v1[i] = mp[bolts[i]];
        }

        sort(v1.begin(), v1.end());
        for (int i = 0; i < n; i++)
        {
            nuts[i] = a[v[i]];
        }
        for (int i = 0; i < n; i++)
        {
            bolts[i] = a[v1[i]];
        }
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
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++)
        {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
