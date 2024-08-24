#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
        {
            return false;
        }
        else if (n == 1)
        {
            return true;
        }
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};