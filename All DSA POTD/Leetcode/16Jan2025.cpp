#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        const int xors1 = accumulate(nums1.begin(), nums1.end(), 0, [](int a, int b)
                                     { return a ^ b; });
        const int xors2 = accumulate(nums2.begin(), nums2.end(), 0, [](int a, int b)
                                     { return a ^ b; });
        return (nums1.size() % 2 * xors2) ^ (nums2.size() % 2 * xors1);
    }
};