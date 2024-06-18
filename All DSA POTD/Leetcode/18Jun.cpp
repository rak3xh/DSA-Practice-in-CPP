#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int ans = 0;
        vector<pair<int, int>> jobs;

        for (int i = 0; i < difficulty.size(); ++i)
            jobs.emplace_back(difficulty[i], profit[i]);

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int i = 0;
        int maxProfit = 0;

        for (const int w : worker)
        {
            for (; i < jobs.size() && w >= jobs[i].first; ++i)
                maxProfit = max(maxProfit, jobs[i].second);
            ans += maxProfit;
        }

        return ans;
    }
};