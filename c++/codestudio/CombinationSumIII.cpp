#include <bits/stdc++.h>
using namespace std;

void combi(int ind, int k, int n, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ds.size() == k && n == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i <= 9; i++)
    {
        if (n < i)
            continue;
        ds.push_back(i);
        combi(i + 1, k, n - i, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> ds;
    combi(1, k, n, ans, ds);
    sort(ans.begin(), ans.end());
    return ans;
}