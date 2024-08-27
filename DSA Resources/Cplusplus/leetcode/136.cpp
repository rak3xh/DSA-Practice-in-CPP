#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (const int num : nums)
        {
            ans = ans ^ num;
        }
        return ans;
    }
};