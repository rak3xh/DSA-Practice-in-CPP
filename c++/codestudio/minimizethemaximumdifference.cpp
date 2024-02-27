#include <bits/stdc++.h>
using namespace std;
int maxAdjDifference(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> diff(n - 1, 0);
    for (int i = 1; i < n; i++)
    {
        diff[i - 1] = arr[i] - arr[i - 1];
    }
    int mn = INT_MAX;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n - k - 1; i++)
    {
        pq.push({diff[i], i});
    }
    mn = min(mn, pq.top().first);
    for (int i = n - k - 1; i < n - 1; i++)
    {
        pq.push({diff[i], i});
        while (pq.top().second <= i - (n - k - 1))
            pq.pop();
        mn = min(mn, pq.top().first);
    }
    return mn;
}
int main()
{
}