#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        const long MOD = 1000000007;
        unordered_map<int, long> countByY;

        // Count points by Y-coordinate
        for (const auto &p : points)
        {
            countByY[p[1]]++;
        }

        // Extract and sort unique Y-coordinates
        vector<int> yCord;
        yCord.reserve(countByY.size());
        for (auto &it : countByY)
        {
            yCord.push_back(it.first);
        }
        sort(yCord.begin(), yCord.end());

        // Compute number of horizontal pairs for each Y
        vector<long> hPlanes;
        hPlanes.reserve(yCord.size());
        for (int y : yCord)
        {
            long c = countByY[y];
            if (c >= 2)
                hPlanes.push_back(c * (c - 1) / 2);
            else
                hPlanes.push_back(0L);
        }

        long prefix = 0;
        long result = 0;

        // Compute trapezoid count
        for (long h : hPlanes)
        {
            result = (result + (prefix * (h % MOD)) % MOD) % MOD;
            prefix = (prefix + h) % MOD;
        }

        return (int)result;
    }
};