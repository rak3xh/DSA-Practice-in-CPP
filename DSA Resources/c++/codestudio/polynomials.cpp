#include <bits/stdc++.h>
using namespace std;
void polymake(vector<int> &a, vector<int> &b, int n, vector<int> &ans)
{
    int x = 0;
    int reach = (2 * n) - 1;
    for (int y = 0; y < reach; y++)
    {
        int sum = 0;
        for (int j = y; j >= 0; j--)
        {
            if ((j < n && j >= 0) && x < n)
            {
                sum = sum + (a[x] * b[j]);
            }
            x++;
        }
        x = 0;
        ans.push_back(sum);
    }
    return;
}
vector<int> multiply(vector<int> &a, vector<int> &b, int n)
{
    vector<int> ans;
    polymake(a, b, n, ans);
    return ans;
}