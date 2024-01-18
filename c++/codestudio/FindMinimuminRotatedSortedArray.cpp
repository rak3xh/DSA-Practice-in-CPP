#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int findMin(vector<int> &arr)
{
    // Write your code here.
    int low = 0, high = arr.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // If the mid element is greater than the last element, search in the right half
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        // If the mid element is less than or equal to the last element, search in the left half
        else
        {
            high = mid;
        }
    }

    // The minimum element will be at the 'low' index
    return arr[low];
}