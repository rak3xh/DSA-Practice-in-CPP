#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSquareArea(int m, int n,
                           vector<int> &hFences,
                           vector<int> &vFences)
    {
        const int kMod = 1000000007;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hGaps = getGaps(hFences);
        unordered_set<int> vGaps = getGaps(vFences);

        int maxGap = -1;
        for (int hGap : hGaps)
        {
            if (vGaps.find(hGap) != vGaps.end())
                maxGap = max(maxGap, hGap);
        }

        if (maxGap == -1)
            return -1;

        long long area = 1LL * maxGap * maxGap;
        return area % kMod;
    }

private:
    unordered_set<int> getGaps(const vector<int> &fences)
    {
        unordered_set<int> gaps;
        int sz = fences.size();
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                gaps.insert(fences[i] - fences[j]);
            }
        }
        return gaps;
    }
};
