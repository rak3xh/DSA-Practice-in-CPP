#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());

        while (l < r)
        {
            int m = (l + r) / 2;
            if (numStores(quantities, m) <= n)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

private:
    int numStores(const vector<int> &quantities, int m)
    {
        int subtotal = 0;
        for (int q : quantities)
        {
            subtotal += (q + m - 1) / m; // Equivalent to ceil(q / m)
        }
        return subtotal;
    }
};
