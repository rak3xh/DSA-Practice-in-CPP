#include <bits/stdc++.h>
using namespace std;

struct T
{
    int i;
    int j;
    int num; // nums[i][j]
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        auto compare = [&](const T &a, const T &b)
        {
            return a.num > b.num;
        };
        priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
        int mn = INT_MAX;
        int mx = INT_MIN;

        // Initialize the minHeap with the first element of each list
        for (int i = 0; i < nums.size(); ++i)
        {
            const int num = nums[i][0];
            minHeap.push({i, 0, num});
            mn = min(mn, num);
            mx = max(mx, num);
        }

        int minRange = mn;
        int maxRange = mx;

        // Process the elements in the heap
        while (minHeap.size() == nums.size())
        {
            T top = minHeap.top();
            minHeap.pop();
            int i = top.i;
            int j = top.j;

            if (j + 1 < nums[i].size())
            {
                minHeap.push({i, j + 1, nums[i][j + 1]});
                mx = max(mx, nums[i][j + 1]);
                mn = minHeap.top().num;

                if (mx - mn < maxRange - minRange)
                {
                    minRange = mn;
                    maxRange = mx;
                }
            }
        }

        return {minRange, maxRange};
    }
};
