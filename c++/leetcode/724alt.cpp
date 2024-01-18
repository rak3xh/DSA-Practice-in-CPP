#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        int leftsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum - nums[i];
            if (leftsum == sum)
            {
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
} obj;
int main()
{
    vector<int> a{1, 7, 3, 6, 5, 6};
    int index = obj.pivotIndex(a);
    cout << index;
}