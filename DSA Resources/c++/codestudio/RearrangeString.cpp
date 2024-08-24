#include <bits/stdc++.h>
using namespace std;
string reArrangeString(string &s)
{
    // Write your code here.
    unordered_map<char, int> charFreq;
    priority_queue<pair<int, char>> maxHeap;
    for (char c : s)
    {
        charFreq[c]++;
    }
    for (auto it : charFreq)
    {
        maxHeap.push({it.second, it.first});
    }

    string result = "";

    while (!maxHeap.empty())
    {
        pair<int, char> first = maxHeap.top();
        maxHeap.pop();
        if (result.empty() || result.back() != first.second)
        {
            result += first.second;
            if (--first.first > 0)
            {
                maxHeap.push(first);
            }
        }
        else
        {
            if (maxHeap.empty())
            {
                return "not possible";
            }
            pair<int, char> second = maxHeap.top();
            maxHeap.pop();
            result += second.second;
            if (--second.first > 0)
            {
                maxHeap.push(second);
            }
            maxHeap.push(first);
        }
    }
    return result;
}
