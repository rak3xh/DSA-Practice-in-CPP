#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int counter = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                counter++;
            }
        }
        if (counter <= 1)
        {
            return true;
        }
        else
            return false;
    }
};