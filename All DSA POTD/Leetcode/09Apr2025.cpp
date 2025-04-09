#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        const unordered_set<int> numsSet{nums.begin(), nums.end()};
        const int mn = *min_element(nums.begin(), nums.end());
        if (mn < k)
            return -1;
        if (mn > k)
            return numsSet.size();
        return numsSet.size() - 1;
    }
};