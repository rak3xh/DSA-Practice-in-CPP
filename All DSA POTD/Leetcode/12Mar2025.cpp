// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        return max(count_if(nums.begin(), nums.end(), [](int num)
                            { return num > 0; }),
                   count_if(nums.begin(), nums.end(), [](int num)
                            { return num < 0; }));
    }
};
// C++ 20 SOlution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maximumCount(vector<int> &nums)
    {
        return max(ranges::count_if(nums, [](int num)
        { return num > 0; }),
        ranges::count_if(nums, [](int num)
        { return num < 0; }));
    }
};
*/