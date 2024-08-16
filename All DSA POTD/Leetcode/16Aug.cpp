#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int ans = 0;
        int mn = 10000;
        int mx = -10000;

        for (const vector<int> &A : arrays)
        {
            ans = max({ans, A.back() - mn, mx - A.front()});
            mn = min(mn, A.front());
            mx = max(mx, A.back());
        }

        return ans;
    }
};