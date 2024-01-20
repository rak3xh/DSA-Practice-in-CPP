#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    // function of binary search for O(log n) complexity
    int binarySearch(vector<int> &arr, int s, int e, int k)
    {
        int start = s;
        int end = e;
        int mid = start + (end - start) / 2; // for exceeding value of integer from 2^31-1
        while (start <= end)
        {
            if (arr[mid] == k)
            {
                return mid;
            }
            if (k > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return -1;
    }

    // for searching pivot element
    int findPivot(vector<int> &arr, int n)
    {
        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (arr[mid] >= arr[0])
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

public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int pivot = findPivot(nums, n);
        if (target >= nums[pivot] && target <= nums[n - 1])
        {
            return binarySearch(nums, pivot, n - 1, target);
        }
        else
        {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};