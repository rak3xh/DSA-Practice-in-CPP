#include <bits/stdc++.h>
using namespace std;

int pickCoupons(int n, vector<int> &arr)
{
    // Write your code here
    int mini = 10000;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                ans = (j - i) + 1;
                mini = min(ans, mini);
            }
        }
    }
    if (mini == 10000)
    {
        mini = -1;
    }
    return mini;
}