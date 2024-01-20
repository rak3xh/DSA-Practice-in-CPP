#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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

int search(vector<int> &arr, int n, int k)
{
    int pivot = findPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, k);
    }
}
