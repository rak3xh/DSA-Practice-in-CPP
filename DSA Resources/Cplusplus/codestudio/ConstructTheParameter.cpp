#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    Where 'N' is the number of points.
*/

long long cross(vector<int> p, vector<int> q, vector<int> r)
{
    long long ax = r[0] - p[0];
    long long ay = r[1] - p[1];
    long long bx = q[0] - p[0];
    long long by = q[1] - p[1];
    return ax * by - ay * bx;
}

vector<vector<int>> construct(vector<vector<int>> Points)
{
    sort(Points.begin(), Points.end());
    int n = Points.size();

    vector<vector<int>> up, down;
    // Finding the upper hull/parameter.
    up.push_back(Points[0]);
    up.push_back(Points[1]);
    for (int i = 2; i < n; i++)
    {
        while (up.size() >= 2)
        {
            int m = up.size();
            // Checking if the point turned left or not.
            if (cross(up[m - 1], up[m - 2], Points[i]) > 0)
            {
                up.pop_back();
            }
            else
            {
                break;
            }
        }
        up.push_back(Points[i]);
    }
    // Finding the lower hull/parameter.
    down.push_back(Points[n - 1]);
    down.push_back(Points[n - 2]);
    for (int i = n - 3; i >= 0; i--)
    {
        while (down.size() >= 2)
        {
            int m = down.size();
            // Checking if the point turned left or not.
            if (cross(down[m - 1], down[m - 2], Points[i]) > 0)
            {
                down.pop_back();
            }
            else
            {
                break;
            }
        }
        down.push_back(Points[i]);
    }
    // Finding the distinct points in 'up' + 'down'.
    set<vector<int>> s;
    vector<vector<int>> ans;
    for (auto &i : up)
    {
        if (s.find(i) == s.end())
        {
            ans.push_back(i);
            s.insert(i);
        }
    }
    for (auto &i : down)
    {
        if (s.find(i) == s.end())
        {
            ans.push_back(i);
            s.insert(i);
        }
    }
    return ans;
}