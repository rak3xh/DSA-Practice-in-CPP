#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int ans = 0;

        while (hasInversion(nums))
        {
            vector<int> pairSums;

            // Build pair sums manually
            for (int i = 0; i + 1 < (int)nums.size(); i++)
            {
                pairSums.push_back(nums[i] + nums[i + 1]);
            }

            // Find minimum pair sum
            int minPairSum = *min_element(pairSums.begin(), pairSums.end());

            // Find index of first occurrence of min sum
            int minPairIndex = 0;
            for (int i = 0; i < (int)pairSums.size(); i++)
            {
                if (pairSums[i] == minPairSum)
                {
                    minPairIndex = i;
                    break;
                }
            }

            // Replace first element of pair with sum
            nums[minPairIndex] = minPairSum;

            // Remove second element of the pair
            nums.erase(nums.begin() + minPairIndex + 1);

            ++ans;
        }

        return ans;
    }

private:
    bool hasInversion(const vector<int> &nums)
    {
        for (int i = 0; i + 1 < (int)nums.size(); i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};
