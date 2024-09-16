// Binary Search
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int a[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (a[mid] == target)
        {
            return mid;
        }
        else if (target > a[mid])
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
int main()
{
    int n;
    cin >> n;
    int a[50];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target;
    cin >> target;
    int ans = binarySearch(a, n, target);
    cout << ans;
}