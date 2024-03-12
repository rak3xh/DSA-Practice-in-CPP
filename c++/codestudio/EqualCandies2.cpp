#include <bits/stdc++.h>
using namespace std;

long long int equalCandies(vector<int> &candies, int n)
{
    // Write your code here.
    vector<int> ans;
    int cnt = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (candies[i] > max)
        {
            max = candies[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (candies[i] < min)
        {
            min = candies[i];
        }
    }
    while (min <= max)
    {
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (candies[i] == min)
            {
                continue;
            }
            else if (candies[i] > min)
            {
                cnt = cnt + (candies[i] - min);
            }
            else if (candies[i] < min)
            {
                cnt = cnt + (min - candies[i]);
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