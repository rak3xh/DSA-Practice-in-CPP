#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> recamanSequence(int n)
    {
        // code here
        vector<int> ans(n, 0);
        unordered_set<int> set;
        for (int i = 1; i < n; i++)
        {
            if (set.find(ans[i - 1] - i) == set.end() && ans[i - 1] - i > 0)
                ans[i] = ans[i - 1] - i;
            else
                ans[i] = ans[i - 1] + i;
            set.insert(ans[i]);
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
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}