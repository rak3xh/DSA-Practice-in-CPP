#include <bits/stdc++.h>
using namespace std;
int firstoccur(vector<int> &a, int n, int k)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (a[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (k > a[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int Lastoccur(vector<int> &a, int n, int k)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (a[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (k > a[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    // Write your code here
    pair<int, int> p;
    p.first = (firstoccur(arr, n, k));
    p.second = (Lastoccur(arr, n, k));
    return p;
}