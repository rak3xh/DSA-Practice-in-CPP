#include <bits/stdc++.h>
using namespace std;

long long int equalCandies(vector<int> &arr, int n)

{

    // Write your code here.

    vector<int> ans;

    int cnt = 0;

    int max = INT_MIN;

    int min = INT_MAX;

    for (int i = 0; i < n; i++)

    {

        if (arr[i] > max)

        {

            max = arr[i];
        }
    }

    for (int i = 0; i < n; i++)

    {

        if (arr[i] < min)

        {

            min = arr[i];
        }
    }

    while (min <= max)

    {

        cnt = 0;

        for (int i = 0; i < n; i++)

        {

            if (arr[i] == min)

            {

                continue;
            }

            else if (arr[i] > min)

            {

                cnt = cnt + (arr[i] - min);
            }

            else if (arr[i] < min)

            {

                cnt = cnt + (min - arr[i]);
            }
        }

        ans.push_back(cnt);

        min = min + 1;
    }

    int mini = INT_MAX;

    for (int i = 0; i < ans.size(); i++)

    {

        if (ans[i] < mini)

        {

            mini = ans[i];
        }
    }

    return mini;
}