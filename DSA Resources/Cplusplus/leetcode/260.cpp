#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long long xs = 0;
        for (int &x : nums)
        {
            xs ^= x;
        }
        int lb = xs & -xs;
        int a = 0;
        for (int &x : nums)
        {
            if (x & lb)
            {
                a ^= x;
            }
        }
        int b = xs ^ a;
        return {a, b};
    }
};