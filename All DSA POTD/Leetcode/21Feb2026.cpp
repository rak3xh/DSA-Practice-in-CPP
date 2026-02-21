#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        const int magic = 665772; // bitmask for prime counts
        int ans = 0;

        for (int num = left; num <= right; ++num)
        {
            int bits = __builtin_popcount(num); // C++14 compatible
            if ((magic >> bits) & 1)
                ++ans;
        }
        return ans;
    }
};