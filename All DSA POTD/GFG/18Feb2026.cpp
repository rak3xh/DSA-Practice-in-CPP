#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long merge(vector<int> &arr, vector<int> &temp,
                    int left, int mid, int right)
    {

        int i = left;
        int j = mid + 1;
        int k = left;
        long long inv_count = 0;

        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inv_count += (mid - i + 1);
            }
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (int x = left; x <= right; x++)
            arr[x] = temp[x];

        return inv_count;
    }

    long long mergeSort(vector<int> &arr, vector<int> &temp,
                        int left, int right)
    {

        long long inv_count = 0;

        if (left < right)
        {
            int mid = (left + right) / 2;

            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);

            inv_count += merge(arr, temp, left, mid, right);
        }

        return inv_count;
    }
    long long inversionCount(vector<int> &arr)
    {
        // Code Here
        int n = arr.size();
        vector<int> temp(n);
        return mergeSort(arr, temp, 0, n - 1);
    }
};