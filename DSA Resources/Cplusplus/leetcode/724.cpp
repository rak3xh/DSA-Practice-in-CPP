#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int leftsum = 0, rightsum = 0;
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        for (int i = 0; i < mid; i++)
        {
            leftsum = leftsum + nums[i];
        }
        for (int i = mid + 1; i < nums.size(); i++)
        {
            rightsum = rightsum + nums[i];
        }
        while (mid != s && mid != e)
        {

            if (leftsum == rightsum)
            {
                return mid - 1;
            }
            else if (leftsum < rightsum)
            {
                mid = mid + 1;
                leftsum = leftsum + nums[mid];
            }
            else
            {
                mid = mid - 1;
                rightsum = rightsum + nums[mid];
            }
        }
        if (mid == s || mid == e && leftsum == rightsum)
        {
            return 0;
        }
        return -1;
    }
} obj;
int main()
{
    vector<int> a{-1, -1, -1, -1, -1, -1};
    int index = obj.pivotIndex(a);
    cout << index;
}