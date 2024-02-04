#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int position = 0;      // Initial position of the ant
        int boundaryCount = 0; // Number of times the ant returns to the boundary

        for (int num : nums)
        {
            if (num < 0)
            {
                position -= abs(num);
            }
            else
            {
                position += num;
            }

            // Check if the ant is on the boundary after moving |num| units
            if (position == 0)
            {
                boundaryCount++;
            }
        }

        return boundaryCount;
    }
};