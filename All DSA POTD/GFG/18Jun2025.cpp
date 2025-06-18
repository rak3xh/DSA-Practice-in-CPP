#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int i, string &s, vector<string> &v, vector<vector<string>> &ans)
    {
        if (i >= s.size())
        {
            ans.push_back(v);
            return;
        }
        for (int j = i; j < s.size(); j++)
        {
            string p = s.substr(i, j - i + 1);
            string r = p;
            reverse(p.begin(), p.end());
            if (p == r)
            {
                v.push_back(p);
                solve(j + 1, s, v, ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s)
    {
        // code here
        vector<vector<string>> ans;
        vector<string> v;
        solve(0, s, v, ans);
        return ans;
    }
};