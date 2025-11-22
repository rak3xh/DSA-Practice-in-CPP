#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int totalOperations = 0;

        // Iterate through each number in the array
        for (int num : nums)
        {
            // Calculate remainder when divided by 3
            int remainder = num % 3;

            // If remainder is not 0, the number is not divisible by 3
            if (remainder != 0)
            {
                // We can either subtract remainder or add (3 - remainder) to make it divisible by 3
                // Choose the minimum of the two options
                totalOperations += min(remainder, 3 - remainder);
            }
        }

        return totalOperations;
    }
};