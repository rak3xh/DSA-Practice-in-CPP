#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countDigit(int n)
    {
        int digit = 0;
        while (n != 0)
        {
            n = n / 10;
            digit++;
        }
        return digit;
    }
    int findNumbers(vector<int> &nums)
    {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int noOfDigit = countDigit(nums[i]);
            if (noOfDigit % 2 == 0)
            {
                counter++;
            }
        }
        return counter;
    }
};