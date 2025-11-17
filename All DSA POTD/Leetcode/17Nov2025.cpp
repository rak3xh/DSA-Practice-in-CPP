#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        if (k == 0)
            return true;

        int n = nums.size();
        int curr = 0;
        int next = 1;

        while (curr < n && next < n)
        {
            if (nums[next] == 1)
            {
                if (nums[curr] == 1 && next - curr <= k)
                    return false;
                curr = next;
            }
            next++;
        }

        return true;
    }
};