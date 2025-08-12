#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> minMaxCandy(vector<int> &prices, int k)
    {
        // Code here
        sort(prices.begin(), prices.end());
        int n = prices.size();
        vector<int> res;

        // for every 1 candy you take, you get k free
        // so you can break the n candies in groups of k + 1 (1 that you bought, k free)
        // you can get 1 group worth of candies by buying one candy
        double freeCandiesPerCandy = (double)n / (k + 1);
        // since you can't buy a fractional candy, ceil to count the fraction as a whole candy
        // you neeed to buy these many candies to get all the candies
        int candiesNeeded = ceil(freeCandiesPerCandy);
        int maxCount = 0, minCount = 0;
        for (int i = 0; i < candiesNeeded; i++)
        {
            // select from the back for most expensive candies
            maxCount += prices[n - i - 1];
            // select from the front for the cheapest
            minCount += prices[i];
        }

        res.push_back(minCount);
        res.push_back(maxCount);

        return res;
    }
};