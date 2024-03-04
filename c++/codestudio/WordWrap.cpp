#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>

using namespace std;

int wordWrap(vector<string> words, int m, int n)
{
    vector<int> len(n);
    for (int i = 0; i < n; i++)
    {
        len[i] = words[i].size();
    }

    int cost[n][n];
    for (int i = 0; i < n; i++)
    {
        cost[i][i] = m - len[i];
        for (int j = i + 1; j < n; j++)
        {
            cost[i][j] = cost[i][j - 1] - len[j] - 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (cost[i][j] < 0)
            {
                cost[i][j] = INT_MAX;
            }
            else
            {
                cost[i][j] = cost[i][j] * cost[i][j] * cost[i][j];
            }
        }
    }

    int mincost[n];
    for (int i = n - 1; i >= 0; i--)
    {
        mincost[i] = cost[i][n - 1];
        for (int j = n - 1; j > i; j--)
        {
            if (cost[i][j - 1] == INT_MAX)
            {
                continue;
            }

            if (mincost[i] > cost[i][j - 1] + mincost[j])
            {
                mincost[i] = cost[i][j - 1] + mincost[j];
            }
        }
    }
    return mincost[0];
}
int main()
{
}