#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval)
    {
        // code here
        int start = newInterval[0], end = newInterval[1];
        vector<vector<int>> ans;
        int l, r = INT_MIN, c = -1;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            int a = intervals[i][0], b = intervals[i][1];
            if (b < start)
            {
                ans.push_back({a, b});
            }
            else if (c == -1 && max(a, start) <= min(b, end))
            {
                start = min(start, a);
                end = max(end, b);
            }
            else
            {
                if (c == -1)
                {
                    c = 0;
                    ans.push_back({start, end});
                }
                ans.push_back({a, b});
            }
        }
        if (c == -1)
        {
            ans.push_back({start, end});
        }
        return ans;
    }
};