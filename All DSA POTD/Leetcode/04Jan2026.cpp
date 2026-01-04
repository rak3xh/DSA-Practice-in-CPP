#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int totalSum = 0;

        // Process each number in the array
        for (int number : nums)
        {
            totalSum += getSumIfExactlyFourDivisors(number);
        }

        return totalSum;
    }

private:
    int getSumIfExactlyFourDivisors(int number)
    {
        // Initialize with 2 divisors (1 and the number itself)
        int divisorCount = 2;
        int divisorSum = 1 + number;

        // Check for divisors from 2 to sqrt(number)
        for (int i = 2; i * i <= number; ++i)
        {
            if (number % i == 0)
            {
                // Found a divisor
                divisorCount++;
                divisorSum += i;

                // Check if the corresponding divisor is different
                // (avoid counting perfect squares twice)
                if (i * i != number)
                {
                    divisorCount++;
                    divisorSum += number / i;
                }
            }
        }

        // Return the sum only if there are exactly 4 divisors
        return (divisorCount == 4) ? divisorSum : 0;
    }
};