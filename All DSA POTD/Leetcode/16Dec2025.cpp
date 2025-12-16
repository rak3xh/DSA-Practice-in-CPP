#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, budget;
    vector<int> present, future;
    vector<vector<int>> tree;

    // Merge two knapsack dp arrays
    vector<long long> mergeDP(const vector<long long> &A,
                              const vector<long long> &B)
    {
        vector<long long> merged(budget + 1, LLONG_MIN);

        for (int i = 0; i <= budget; i++)
        {
            if (A[i] == LLONG_MIN)
                continue;
            for (int j = 0; j + i <= budget; j++)
            {
                if (B[j] == LLONG_MIN)
                    continue;
                merged[i + j] = max(merged[i + j], A[i] + B[j]);
            }
        }
        return merged;
    }

    // Returns {noDiscountDP, withDiscountDP}
    pair<vector<long long>, vector<long long>> dfs(int u, int parent)
    {
        vector<long long> noDiscount(budget + 1, 0);
        vector<long long> withDiscount(budget + 1, 0);

        for (int v : tree[u])
        {
            if (v == parent)
                continue;
            auto child = dfs(v, u);
            noDiscount = mergeDP(noDiscount, child.first);
            withDiscount = mergeDP(withDiscount, child.second);
        }

        vector<long long> newDp0 = noDiscount;
        vector<long long> newDp1 = noDiscount;

        // 1. Buy at full cost
        int fullCost = present[u];
        long long profitFull = future[u] - fullCost;
        for (int b = fullCost; b <= budget; b++)
        {
            if (withDiscount[b - fullCost] != LLONG_MIN)
            {
                newDp0[b] = max(newDp0[b],
                                withDiscount[b - fullCost] + profitFull);
            }
        }

        // 2. Buy at half cost (discount)
        int halfCost = present[u] / 2;
        long long profitHalf = future[u] - halfCost;
        for (int b = halfCost; b <= budget; b++)
        {
            if (withDiscount[b - halfCost] != LLONG_MIN)
            {
                newDp1[b] = max(newDp1[b],
                                withDiscount[b - halfCost] + profitHalf);
            }
        }

        return {newDp0, newDp1};
    }

    int maxProfit(int n_,
                  vector<int> &present_,
                  vector<int> &future_,
                  vector<vector<int>> &hierarchy_,
                  int budget_)
    {
        n = n_;
        present = present_;
        future = future_;
        budget = budget_;

        tree.assign(n, {});
        for (auto &e : hierarchy_)
        {
            int u = e[0] - 1;
            int v = e[1] - 1;
            tree[u].push_back(v);
        }

        auto result = dfs(0, -1);
        return *max_element(result.first.begin(), result.first.end());
    }
};
