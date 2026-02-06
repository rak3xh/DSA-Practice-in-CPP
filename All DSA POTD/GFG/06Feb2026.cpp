#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> smallestDiff(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        // code here.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int n = a.size();
        int i = 0;
        int j = 0;
        int k = 0;
        int diff = INT_MAX;
        int sum = INT_MAX;
        vector<int> ans = {-1, -1, -1};
        while (i < n && j < n && k < n)
        {
            int mx = max({a[i], b[j], c[k]});
            int mn = min({a[i], b[j], c[k]});
            int curr = a[i] + b[j] + c[k];
            int d = mx - mn;
            if (d < diff)
            {
                diff = d;
                sum = curr;
                ans = {a[i], b[j], c[k]};
            }
            else if (d == diff && curr < sum)
            {
                sum = curr;
                ans = {a[i], b[j], c[k]};
            }
            if (a[i] < b[j] && a[i] < c[k])
            {
                i++;
                continue;
            }
            if (a[i] > b[j] && b[j] < c[k])
            {
                j++;
                continue;
            }
            if (a[i] > c[k] && b[j] > c[k])
            {
                k++;
                continue;
            }
            if (a[i] == b[j] && b[j] == c[k])
            {
                break;
            }
            if (a[i] == b[j])
            {
                j++;
                continue;
            }
            if (c[k] == b[j])
            {
                k++;
                continue;
            }
            if (a[i] == c[k])
            {
                i++;
                continue;
            }
        }
        sort(ans.rbegin(), ans.rend());
        return ans;
    }
};