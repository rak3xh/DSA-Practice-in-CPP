#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countRevPairs(vector<int> &arr)
    {
        // Code here
        return mergeSortCount(arr, 0, arr.size() - 1);
    }

private:
    int mergeSortCount(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return 0;

        int mid = (low + high) / 2;
        int count = mergeSortCount(arr, low, mid);
        count += mergeSortCount(arr, mid + 1, high);
        count += countPairs(arr, low, mid, high);

        // STL inplace_merge merges two sorted halves in place
        inplace_merge(arr.begin() + low, arr.begin() + mid + 1, arr.begin() + high + 1);

        return count;
    }

    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int count = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++)
        {
            while (j <= high && (long long)arr[i] > 2LL * arr[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }

        return count;
    }
};