#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        constexpr int magic = 665772;
        int ans = 0;

        for (unsigned num = left; num <= right; ++num)
            if (magic >> popcount(num) & 1)
                ++ans;

        return ans;
    }
};