#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int FirstOccur(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (target > nums[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
    int LastOccur(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (target > nums[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int first = FirstOccur(nums, target);
        int last = LastOccur(nums, target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};