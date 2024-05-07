#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        while (s < e)
        {
            const int mid = s + (e - s) / 2;
            if (nums[mid] == nums[e])
                --e;
            else if (nums[mid] < nums[e])
                e = mid;
            else
                s = mid + 1;
        }
        return nums[s];
    }
};