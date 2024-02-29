#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &arr)
{
    // Write your code here
    int start = 0, end = arr.size(), mid;

    while (start <= end)

    {

        mid = end + (start - end) / 2;

        // peak element

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])

            return mid;

        // right move

        else if (arr[mid] > arr[mid - 1])

        {

            start = mid + 1;
        }

        else
        {

            end = mid - 1;
        }
    }

    return -1;
}
