#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        long long ans = 0;
        set<pair<int, int>> numAndIndices;
        vector<bool> seen(nums.size(), false);

        // Insert elements into the set as {value, index}
        for (int i = 0; i < nums.size(); ++i)
            numAndIndices.insert({nums[i], i});

        // Iterate through the set of pairs
        for (const auto &p : numAndIndices)
        {
            int num = p.first;
            int i = p.second;

            // Skip if the current index is already marked as seen
            if (seen[i])
                continue;

            // Mark the neighboring indices as seen
            if (i > 0)
                seen[i - 1] = true;
            if (i + 1 < nums.size())
                seen[i + 1] = true;

            // Mark the current index as seen
            seen[i] = true;

            // Add the value to the answer
            ans += num;
        }

        return ans;
    }
};

// C++ 20 Solution

/*
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        long ans = 0;
        set<pair<int, int>> numAndIndices;
        vector<bool> seen(nums.size());

        for (int i = 0; i < nums.size(); ++i)
            numAndIndices.insert({nums[i], i});

        for (const auto &[num, i] : numAndIndices)
        {
            if (seen[i])
                continue;
            if (i > 0)
                seen[i - 1] = true;
            if (i + 1 < nums.size())
                seen[i + 1] = true;
            seen[i] = true;
            ans += num;
        }

        return ans;
    }
};
*/