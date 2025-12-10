#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPermutations(vector<int> &complexity)
    {
        const int MOD = 1000000007;

        // Initialize result variable to store the count of valid permutations
        long long result = 1;

        // Iterate through the array starting from index 1
        for (int i = 1; i < complexity.size(); ++i)
        {
            // Check if current element is less than or equal to the first element
            // If so, no valid permutation exists where first element is minimum
            if (complexity[i] <= complexity[0])
            {
                return 0;
            }

            // Multiply result by current index (counting valid positions)
            // Apply modulo to prevent overflow
            result = (result * i) % MOD;
        }

        // Return the final count of permutations
        return static_cast<int>(result);
    }
};