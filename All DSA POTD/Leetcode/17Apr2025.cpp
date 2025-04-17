// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, vector<int>> numToIndices;

        for (int i = 0; i < nums.size(); ++i)
            numToIndices[nums[i]].push_back(i);

        for (auto it = numToIndices.begin(); it != numToIndices.end(); ++it)
        {
            vector<int> &indices = it->second;
            unordered_map<int, int> gcds;

            for (int i : indices)
            {
                int gcd_i = __gcd(i, k);
                for (auto jt = gcds.begin(); jt != gcds.end(); ++jt)
                {
                    int gcd_j = jt->first;
                    int count = jt->second;
                    if ((gcd_i * gcd_j) % k == 0)
                        ans += count;
                }
                ++gcds[gcd_i];
            }
        }

        return ans;
    }
};

// C++ 14 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
int countPairs(vector<int> &nums, int k)
{
        int ans = 0;
        unordered_map<int, vector<int>> numToIndices;

        for (int i = 0; i < nums.size(); ++i)
        numToIndices[nums[i]].push_back(i);

        for (const auto &[_, indices] : numToIndices)
        {
            unordered_map<int, int> gcds;
            for (const int i : indices)
            {
                const int gcd_i = gcd(i, k);
                for (const auto &[gcd_j, count] : gcds)
                if (gcd_i * gcd_j % k == 0)
                ans += count;
                ++gcds[gcd_i];
            }
        }

        return ans;
    }
};
*/