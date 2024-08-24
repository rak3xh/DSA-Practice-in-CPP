#include <bits/stdc++.h>
using namespace std;
int getNewNum(vector<int> arr, int n)
{
    // Write your code here.
    vector<int> ans(32, 0);

    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)

    {

        maxi = max(maxi, arr[i]);
    }

    int len = 0;

    while (maxi != 0)

    {

        maxi = maxi >> 1;

        len++;
    }

    for (int j = 0; j < len; j++)

    {

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {

            cnt += (arr[i] & 1);

            arr[i] = arr[i] >> 1;
        }

        if (cnt >= (n / 2) + 1)

            ans[j] = 1;
    }

    int a = 0;

    for (int i = 0; i < len; i++)

    {

        a = a + ans[i] * pow(2, i);
    }

    return a;
}