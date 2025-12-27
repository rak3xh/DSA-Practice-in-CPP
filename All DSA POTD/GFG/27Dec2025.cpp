#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        // code here
        int l = mat[0][0], r = mat.back().back();
        while (l <= r)
        {
            int m = l + (r - l) / 2;

            int pos = get_less_than_or_equal_to(mat, m);

            if (pos < k)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
    int get_less_than_or_equal_to(vector<vector<int>> &mat, int n)
    {
        int count = 0;
        for (const auto &row : mat)
        {
            auto it = std::upper_bound(row.begin(), row.end(), n);
            count += (it - row.begin());
        }
        return count;
    }
};
