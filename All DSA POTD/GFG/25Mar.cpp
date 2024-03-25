#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<string> v;

    void generate(string s, int size, int ones, int zeros, int n)
    {
        if (size == n)
        {
            v.push_back(s);
            return;
        }
        generate(s + "1", size + 1, ones + 1, zeros, n);
        if (ones >= zeros + 1)
            generate(s + "0", size + 1, ones, zeros + 1, n);
    }
    vector<string> NBitBinary(int n)
    {
        // Your code goes here
        string s = "1";
        generate(s, 1, 1, 0, n);
        sort(v.rbegin(), v.rend());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> ans = ob.NBitBinary(n);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}