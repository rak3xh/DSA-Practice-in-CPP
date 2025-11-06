#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfWays(int n)
    {
        // code here
        if (n == 0 || n == 1)
            return 1;
        if (n < 0)
            return 0;
        int ans = 2 * numberOfWays(n - 2) + numberOfWays(n - 3);
        return ans;
    }
};