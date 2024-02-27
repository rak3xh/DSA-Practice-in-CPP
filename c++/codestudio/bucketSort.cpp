#include <bits/stdc++.h>
using namespace std;
void merge(vector<double> &arr, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    vector<double> temp(high - low + 1);
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[k++];
    }
}
void mergesort(vector<double> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
vector<double> sortArray(int n, vector<double> &arr)
{
    // Write your code here.
    vector<double> buckets[n];
    for (int i = 0; i < arr.size(); i++)
    {
        int ele = arr[i] * n;
        buckets[ele].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        mergesort(buckets[i], 0, buckets[i].size() - 1);
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
    return arr;
}