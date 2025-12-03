// // UnOptimized Code
// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int countTrapezoids(vector<vector<int>> &points)
//     {
//         int n = points.size();
//         double INF = 1e9 + 7;

//         unordered_map<double, vector<double>> slopeToIntercept;
//         unordered_map<long long, vector<double>> midpointToSlope;

//         long long ans = 0;

//         for (int i = 0; i < n; i++)
//         {
//             int x1 = points[i][0];
//             int y1 = points[i][1];

//             for (int j = i + 1; j < n; j++)
//             {
//                 int x2 = points[j][0];
//                 int y2 = points[j][1];

//                 int dx = x1 - x2;
//                 int dy = y1 - y2;

//                 double slope;
//                 double intercept;

//                 if (x1 == x2)
//                 {
//                     slope = INF;
//                     intercept = x1;
//                 }
//                 else
//                 {
//                     slope = 1.0 * (y2 - y1) / (x2 - x1);
//                     intercept = 1.0 * (y1 * dx - x1 * dy) / dx;
//                 }

//                 if (slope == -0.0)
//                     slope = 0.0;
//                 if (intercept == -0.0)
//                     intercept = 0.0;

//                 long long midKey = (long long)(x1 + x2) * 10000LL + (y1 + y2);

//                 slopeToIntercept[slope].push_back(intercept);
//                 midpointToSlope[midKey].push_back(slope);
//             }
//         }

//         for (auto &p : slopeToIntercept)
//         {
//             auto &intercepts = p.second;
//             if (intercepts.size() <= 1)
//                 continue;

//             unordered_map<double, int> freq;
//             for (double b : intercepts)
//                 freq[b]++;

//             long long prefix = 0;
//             for (auto &kv : freq)
//             {
//                 int count = kv.second;
//                 ans += prefix * count;
//                 prefix += count;
//             }
//         }

//         for (auto &p : midpointToSlope)
//         {
//             auto &slopes = p.second;
//             if (slopes.size() <= 1)
//                 continue;

//             unordered_map<double, int> freq;
//             for (double k : slopes)
//                 freq[k]++;

//             long long prefix = 0;
//             for (auto &kv : freq)
//             {
//                 int count = kv.second;
//                 ans -= prefix * count;
//                 prefix += count;
//             }
//         }

//         return (int)ans;
//     }
// };

// Optimized Code
#include <bits/stdc++.h>
using namespace std;

struct PairHash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return ((size_t)p.first << 32) ^ (unsigned int)p.second;
    }
};

class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        int n = points.size();

        unordered_map<pair<int, int>, vector<pair<long long, long long>>, PairHash> slopeToIntercept;
        unordered_map<long long, vector<pair<int, int>>> midpointToSlope;

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dy = y2 - y1;
                int dx = x2 - x1;

                if (dx == 0)
                {
                    dy = 1;
                    dx = 0;
                }
                else
                {
                    int g = __gcd(abs(dy), abs(dx));
                    dy /= g;
                    dx /= g;
                    if (dx < 0)
                    {
                        dx = -dx;
                        dy = -dy;
                    }
                }

                long long num = (long long)y1 * dx - (long long)x1 * dy;
                long long den = dx;

                long long midKey = (long long)(x1 + x2) * 100000 + (y1 + y2);

                slopeToIntercept[{dy, dx}].push_back({num, den});
                midpointToSlope[midKey].push_back({dy, dx});
            }
        }

        for (auto &p : slopeToIntercept)
        {
            auto &vec = p.second;
            if (vec.size() <= 1)
                continue;

            unordered_map<pair<long long, long long>, int, PairHash> freq;
            for (auto &q : vec)
                freq[q]++;

            long long prefix = 0;
            for (auto &kv : freq)
            {
                int c = kv.second;
                ans += prefix * c;
                prefix += c;
            }
        }

        for (auto &p : midpointToSlope)
        {
            auto &vec = p.second;
            if (vec.size() <= 1)
                continue;

            unordered_map<pair<int, int>, int, PairHash> freq;
            for (auto &q : vec)
                freq[q]++;

            long long prefix = 0;
            for (auto &kv : freq)
            {
                int c = kv.second;
                ans -= prefix * c;
                prefix += c;
            }
        }

        return (int)ans;
    }
};
