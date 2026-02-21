#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // code here
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, min(citations[i], n - i));
        }

        return ans;
    }
};