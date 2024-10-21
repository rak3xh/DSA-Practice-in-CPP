#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        size_t ans = 0;
        dfs(s, 0, {}, ans);
        return ans;
    }

private:
    void dfs(const string &s, int start, unordered_set<string> seen, size_t &ans)
    {
        if (start == s.length())
        {
            ans = max(ans, seen.size());
            return;
        }

        for (int i = 1; start + i <= s.length(); ++i)
        {
            const string cand = s.substr(start, i);
            if (seen.find(cand) != seen.end()) // Check if `cand` is already in `seen`
                continue;
            seen.insert(cand);
            dfs(s, start + i, seen, ans);
            seen.erase(cand);
        }
    }
};
