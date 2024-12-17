#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                counter++;
            }
        }
        auto end = remove(nums.begin(), nums.end(), val);
        return counter;
    }
};