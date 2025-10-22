#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int ans = 1;
        int adjustable = 0;
        unordered_map<int, int> count;
        map<int, int> line;
        set<int> candidates;

        for (const int num : nums)
        {
            ++count[num];
            ++line[num - k];
            --line[num + k + 1];
            candidates.insert(num);
            candidates.insert(num - k);
            candidates.insert(num + k + 1);
        }

        for (const int num : candidates)
        {
            auto itLine = line.find(num);
            if (itLine != line.end()) adjustable += itLine->second;
            auto itCount = count.find(num);
            const int countNum = (itCount != count.end()) ? itCount->second : 0;
            const int adjusted = adjustable - countNum;
            ans = max(ans, countNum + min(numOperations, adjusted));
        }

        return ans;
    }
};