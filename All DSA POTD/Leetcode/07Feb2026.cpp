#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int dp = 0;
        int countB = 0;

        for (const char c : s)
            if (c == 'a')
                // 1. Delete 'a'.
                // 2. Keep 'a' and delete the previous 'b's.
                dp = min(dp + 1, countB);
            else
                ++countB;

        return dp;
    }
};