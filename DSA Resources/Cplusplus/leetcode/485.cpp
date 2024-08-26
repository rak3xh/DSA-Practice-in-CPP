#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int counter = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                counter++;
                ans = max(counter, ans);
            }
            else
                counter = 0; // when it is not 1 counter refreshes to 0
        }
        return ans;
    }
};