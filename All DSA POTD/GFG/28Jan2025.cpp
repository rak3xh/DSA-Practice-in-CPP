#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    set<string> solve(string &s)
    {
        set<string> st;
        sort(s.begin(), s.end());
        do
        {
            st.insert(s);
        } while (next_permutation(s.begin(), s.end()));
        return st;
    }
    vector<string> findPermutation(string &s)
    {
        // Code here there
        vector<string> ans;
        set<string> st = solve(s);
        for (string str : st)
        {
            ans.push_back(str);
        }
        return ans;
        // Code here there
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
