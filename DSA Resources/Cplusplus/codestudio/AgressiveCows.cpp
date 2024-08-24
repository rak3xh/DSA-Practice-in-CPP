#include <bits/stdc++.h>
using namespace std;
bool PossibleSolution(vector<int> &stalls, int k, int mid)
{
    int n = stalls.size();
    int CowsCount = 1;
    int LastPosition = stalls[0];
    for (int i = 0; i < n; i++)
    {
        if ((stalls[i] - LastPosition) >= mid)
        {
            CowsCount++;
            if (CowsCount == k)
            {
                return true;
            }
            LastPosition = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int mid = s + (e - s) / 2;
    int ans = 0;
    while (s <= e)
    {
        if (PossibleSolution(stalls, k, mid))
        {
            ans = mid;
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
int main()
{
    vector<int> a{4, 2, 1, 3, 6};
    int k = 2;
    int ans = aggressiveCows(a, k);
    cout << ans;
}