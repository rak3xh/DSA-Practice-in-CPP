#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        vector<int> dp(energy);
        for (int i = energy.size() - 1 - k; i >= 0; --i)
            dp[i] += dp[i + k];
        return *max_element(dp.begin(), dp.end());
    }
};