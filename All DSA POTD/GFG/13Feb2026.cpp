#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumDigit(int num)
    {
        int sum = 0;
        while (num)
        {
            int last = num % 10;
            sum += last;
            num /= 10;
        }
        return sum;
    }
    int getCount(int n, int d)
    {
        // code here
        int low = 0, high = n, ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int digitSum = sumDigit(mid);
            if ((mid - digitSum) >= d)
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (ans == INT_MAX)
        {
            return 0;
        }
        return (n - ans + 1);
    }
};