#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        int ans = 0;
        int mx = -1;
        int secondMax = -1;

        // Replace ranges::sort with std::sort (C++14 compatible)
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 // Sort by end ascending, and if equal end, by start descending
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[0] > b[0];
             });

        for (const vector<int> &interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];

            // both mx and secondMax satisfy the interval
            if (mx >= start && secondMax >= start)
                continue;

            if (mx >= start)
            {
                // mx satisfies, but secondMax does not
                secondMax = mx;
                mx = end; // include end
                ans += 1;
            }
            else
            {
                // both do not satisfy — add two new points
                secondMax = end - 1;
                mx = end;
                ans += 2;
            }
        }
        return ans;
    }
};
