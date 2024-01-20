#include <bits/stdc++.h>
void rearrangeArray(int arr[], int n)
{
    int a[10000] = {0};
    // Write your code here
    for (int i = 0; i < n; i++)
    {
        a[i] = arr[arr[i]];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }
}