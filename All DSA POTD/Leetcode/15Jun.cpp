#include <bits/stdc++.h>
using namespace std;
struct T
{
    int pro;
    int cap;
    T(int pro, int cap) : pro(pro), cap(cap) {}
};
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        auto compareC = [](const T &a, const T &b)
        { return a.cap > b.cap; };
        auto compareP = [](const T &a, const T &b)
        { return a.pro < b.pro; };
        priority_queue<T, vector<T>, decltype(compareC)> minHeap(compareC);
        priority_queue<T, vector<T>, decltype(compareP)> maxHeap(compareP);

        for (int i = 0; i < capital.size(); ++i)
            minHeap.emplace(profits[i], capital[i]);

        while (k--)
        {
            while (!minHeap.empty() && minHeap.top().cap <= w)
                maxHeap.push(minHeap.top()), minHeap.pop();
            if (maxHeap.empty())
                break;
            w += maxHeap.top().pro, maxHeap.pop();
        }

        return w;
    }
};