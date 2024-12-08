#include <bits/stdc++.h>
using namespace std;

// C++ 20 Solution
/*
struct Event
{
    int time;
    int value;
    bool isStart;
};
class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int ans = 0;
        int maxValue = 0;
        vector<Event> evts;

        for (const vector<int> &event : events)
        {
            const int start = event[0];
            const int end = event[1];
            const int value = event[2];
            evts.emplace_back(start, value, true);
            evts.emplace_back(end + 1, value, false);
        }

        ranges::sort(evts, [](const Event &a, const Event &b)
                     { return a.time == b.time ? a.isStart < b.isStart : a.time < b.time; });

        for (const auto &[_, value, isStart] : evts)
            if (isStart)
                ans = max(ans, value + maxValue);
            else
                maxValue = max(maxValue, value);

        return ans;
    }
};
*/

// C++ 14 Solution
struct Event
{
    int time;
    int value;
    bool isStart;

    Event(int t, int v, bool s) : time(t), value(v), isStart(s) {}
};

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int ans = 0;
        int maxValue = 0;
        vector<Event> evts;

        // Convert events into Event objects
        for (const vector<int> &event : events)
        {
            const int start = event[0];
            const int end = event[1];
            const int value = event[2];
            evts.emplace_back(start, value, true);
            evts.emplace_back(end + 1, value, false);
        }

        // Sort events based on time and isStart flag
        sort(evts.begin(), evts.end(), [](const Event &a, const Event &b)
             { return a.time == b.time ? a.isStart < b.isStart : a.time < b.time; });

        // Traverse through the sorted events
        for (const Event &e : evts)
        {
            if (e.isStart)
            {
                ans = max(ans, e.value + maxValue);
            }
            else
            {
                maxValue = max(maxValue, e.value);
            }
        }

        return ans;
    }
};