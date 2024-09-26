#include <bits/stdc++.h>
using namespace std;
class MyCalendar
{
public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto lo = timeline.lower_bound(end);

        if (lo == timeline.begin() || (--lo)->second <= start)
        {
            timeline[start] = end;
            return true;
        }

        return false;
    }

private:
    map<int, int> timeline;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */