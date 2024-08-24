#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        long long int prod = 1;
        for (int i = 0; i <= 15; i++)
        {
            prod = pow(4, i);
            if (prod == n)
            {
                return true;
            }
            if (prod > n)
            {
                return false;
            }
        }
        return false;
    }
};