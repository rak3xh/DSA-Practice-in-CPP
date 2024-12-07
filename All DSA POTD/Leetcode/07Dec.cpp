#include <bits/stdc++.h>
using namespace std;

// C++ 20 Solution
/*
class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1;
        int r = ranges::max(nums);

        while (l < r)
        {
            const int m = (l + r) / 2;
            if (numOperations(nums, m) <= maxOperations)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

private:
    // Returns the number of operations required to make m penalty.
    int numOperations(const vector<int> &nums, int m)
    {
        int operations = 0;
        for (const int num : nums)
            operations += (num - 1) / m;
        return operations;
    }
};
*/
class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (numOperations(nums, m) <= maxOperations)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

private:
    // Returns the number of operations required to make m penalty.
    int numOperations(const vector<int> &nums, int m)
    {
        int operations = 0;
        for (const int num : nums)
            operations += (num - 1) / m;
        return operations;
    }
};