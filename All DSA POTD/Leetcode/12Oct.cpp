#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        priority_queue<int, vector<int>, greater<>> minHeap;

        sort(intervals.begin(), intervals.end());

        for (const vector<int> &interval : intervals)
        {
            // There's no overlap, so we can reuse the same group.
            if (!minHeap.empty() && interval[0] > minHeap.top())
                minHeap.pop();
            minHeap.push(interval[1]);
        }

        return minHeap.size();
    }
};