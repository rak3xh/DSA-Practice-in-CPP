#include <bits/stdc++.h>
using namespace std;

// C++ 14 Solution
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        vector<int> ans(nums.size());
        using P = pair<int, int>; // (nums[i], i)
        priority_queue<P, vector<P>, greater<P>> minHeap;

        for (int i = 0; i < nums.size(); ++i)
            minHeap.emplace(nums[i], i);

        while (k-- > 0)
        {
            auto topElement = minHeap.top();
            minHeap.pop();
            int num = topElement.first;
            int i = topElement.second;
            minHeap.emplace(num * multiplier, i);
        }

        while (!minHeap.empty())
        {
            auto topElement = minHeap.top();
            minHeap.pop();
            int num = topElement.first;
            int i = topElement.second;
            ans[i] = num;
        }

        return ans;
    }
};

// C++ 20 Solution
/*
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        vector<int> ans(nums.size());
        using P = pair<int, int>; // (nums[i], i)
        priority_queue<P, vector<P>, greater<>> minHeap;

        for (int i = 0; i < nums.size(); ++i)
            minHeap.emplace(nums[i], i);

        while (k-- > 0)
        {
            const auto [num, i] = minHeap.top();
            minHeap.pop();
            minHeap.emplace(num * multiplier, i);
        }

        while (!minHeap.empty())
        {
            const auto [num, i] = minHeap.top();
            minHeap.pop();
            ans[i] = num;
        }

        return ans;
    }
};
*/