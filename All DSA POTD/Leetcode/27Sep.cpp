#include <bits/stdc++.h>
using namespace std;
class MyCalendarTwo
{
public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        ++timeline[start];
        --timeline[end];

        int activeEvents = 0;
        for (const auto &entry : timeline)
        {
            activeEvents += entry.second;
            if (activeEvents > 2)
            {
                if (--timeline[start] == 0)
                    timeline.erase(start);
                if (++timeline[end] == 0)
                    timeline.erase(end);
                return false;
            }
        }

        return true;
    }

private:
    map<int, int> timeline;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */