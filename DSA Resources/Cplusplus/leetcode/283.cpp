#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int nonzero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[nonzero] = nums[i];
                nonzero++;
            }
        }
        for (int i = nonzero; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};