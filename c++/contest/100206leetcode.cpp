#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxElementsInSubset(std::vector<int> &nums)
    {
        std::unordered_map<int, int> numCount;

        for (int num : nums)
        {
            // Increment the count for the current element
            numCount[num]++;
        }

        int maxCount = 0;

        for (auto &pair : numCount)
        {
            int num = pair.first;
            int count = pair.second;

            int currentCount = count;

            // Check the powers of 2 for the current num
            for (long long power = num * 2; power <= 1e9; power *= 2)
            {
                if (numCount.count(power))
                {
                    currentCount += numCount[power];
                }
                else
                {
                    break; // Stop checking if the power of 2 is not present
                }
            }

            // Update the maximum count
            maxCount = std::max(maxCount, currentCount);
        }

        return maxCount;
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums1 = {5, 4, 1, 2, 2};
    std::vector<int> nums2 = {1, 3, 2, 4};

    int result1 = solution.maxElementsInSubset(nums1);
    int result2 = solution.maxElementsInSubset(nums2);

    std::cout << "Output 1: " << result1 << std::endl; // Output: 3
    std::cout << "Output 2: " << result2 << std::endl; // Output: 1

    return 0;
}
