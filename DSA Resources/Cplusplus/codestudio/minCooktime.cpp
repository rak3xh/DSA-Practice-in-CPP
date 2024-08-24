#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &rank, int m, int mid)
{
    int dish = 0, m_count = 0;
    int fact = 1, ans = 0;
    for (int i = 0; i < rank.size(); i++)
    {
        while (m_count + (rank[i] * fact) <= mid)
        {
            m_count += rank[i] * fact;

            dish++;
            fact++;
        }

        ans += dish;

        m_count = 0;
        dish = 0;
        fact = 1;
    }
    if (ans >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int minCookTime(vector<int> &rank, int m)
{

    int s = 0, e, ans = 1;
    e = pow(10, 6);
    int output = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(rank, m, mid))
        {
            output = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return output;
}
int main()
{
    vector<int> a{1, 2, 3, 4};
    int m;
    cin >> m;
    int ans = minCookTime(a, m);
    cout << ans;
}
