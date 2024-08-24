#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int findPivot(vector<int> &nums, int n)
    {
        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (nums[mid] >= nums[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }

        return s;
    }
    int BinarySearch(vector<int> &nums, int n, int s, int e, int target)
    {

        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }

        return -1;
    }

public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int pivot = findPivot(nums, n);
        if (target >= nums[pivot] && target <= nums[n - 1])
        {
            return BinarySearch(nums, n, pivot, n - 1, target);
        }
        else
        {
            return BinarySearch(nums, n, 0, pivot - 1, target);
        }
    }
} obj;
int main()
{
    vector<int> a{4, 5, 6, 7, 0, 1, 2};
    int target;
    cin >> target;
    int ans = obj.search(a, target);
    cout << "\n*****\n"
         << ans;
}