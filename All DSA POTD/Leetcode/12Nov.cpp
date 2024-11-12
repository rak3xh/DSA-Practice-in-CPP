#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        vector<int> ans;
        vector<int> prices;
        vector<int> maxBeautySoFar(items.size() + 1);

        // Sorting items based on the first element (price) in ascending order
        sort(items.begin(), items.end());

        // Extracting prices from items
        for (const vector<int> &item : items)
            prices.push_back(item[0]);

        // Computing max beauty so far
        for (int i = 0; i < items.size(); ++i)
            maxBeautySoFar[i + 1] = max(maxBeautySoFar[i], items[i][1]);

        // For each query, find the upper bound of the price in the sorted list of prices
        for (const int query : queries)
        {
            auto it = upper_bound(prices.begin(), prices.end(), query);
            int i = distance(prices.begin(), it);
            ans.push_back(maxBeautySoFar[i]);
        }

        return ans;
    }
};
