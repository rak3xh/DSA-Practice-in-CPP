#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cnt1(int mid, int m, int n)
    {
        int count = 0;
        for (int i = 1; i <= m; ++i)
        {
            count += min(mid / i, n);
        }
        return count;
    }
    int kthSmallest(int m, int n, int k)
    {
        // code here
        int low = 1, high = m * n, ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int cnt = cnt1(mid, m, n);
            if (cnt >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
