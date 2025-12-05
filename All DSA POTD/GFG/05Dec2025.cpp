#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // helper to calculate prefix minimum
    vector<int> calcPreMin(const vector<int> &arr, int k)
    {
        vector<int> pref(k);
        pref[0] = arr[0];
        for (int i = 1; i < k; i++)
            pref[i] = min(pref[i - 1], arr[i]);
        return pref;
    }

    // helper to calculate suffix minimum
    vector<int> calcSuffMin(const vector<int> &arr, int k)
    {
        vector<int> suff(k);
        suff[k - 1] = arr[k - 1];
        for (int i = k - 2; i >= 0; i--)
            suff[i] = min(suff[i + 1], arr[i]);
        return suff;
    }

    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        int k = costs[0].size();

        if (k == 1)
        {
            return n == 1 ? costs[0][0] : -1;
        }

        vector<int> nextRow(k);
        for (int col = 0; col < k; col++)
            nextRow[col] = costs[n - 1][col];

        for (int currRow = n - 2; currRow >= 0; currRow--)
        {

            vector<int> curr(k);
            vector<int> prefMin = calcPreMin(nextRow, k);
            vector<int> suffMin = calcSuffMin(nextRow, k);

            for (int col = 0; col < k; col++)
            {
                int prev = 1000000000; // 1e9
                int nxt = 1000000000;

                if (col > 0)
                    prev = prefMin[col - 1];
                if (col < k - 1)
                    nxt = suffMin[col + 1];

                curr[col] = min(costs[currRow][col] + prev,
                                costs[currRow][col] + nxt);
            }

            nextRow = curr;
        }

        return *min_element(nextRow.begin(), nextRow.end());
    }
};
