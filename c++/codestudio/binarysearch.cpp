#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int search(vector<int> &nums, int target)
{
    // Write your code here.
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
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
    return -1;
}