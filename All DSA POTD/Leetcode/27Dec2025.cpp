#include <bits/stdc++.h>
using namespace std;

struct T
{
    long endTime;
    int roomId;
};

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> count(n, 0);

        sort(meetings.begin(), meetings.end());

        auto compare = [](const T &a, const T &b)
        {
            return a.endTime == b.endTime
                       ? a.roomId > b.roomId
                       : a.endTime > b.endTime;
        };

        priority_queue<T, vector<T>, decltype(compare)> occupied(compare);
        priority_queue<int, vector<int>, greater<int>> availableRoomIds;

        for (int i = 0; i < n; ++i)
            availableRoomIds.push(i);

        for (const vector<int> &meeting : meetings)
        {
            int start = meeting[0];
            int end = meeting[1];

            // Free rooms whose meetings have ended
            while (!occupied.empty() && occupied.top().endTime <= start)
            {
                availableRoomIds.push(occupied.top().roomId);
                occupied.pop();
            }

            if (availableRoomIds.empty())
            {
                T topMeeting = occupied.top();
                occupied.pop();

                int roomId = topMeeting.roomId;
                long newStart = topMeeting.endTime;

                ++count[roomId];
                occupied.push({newStart + (end - start), roomId});
            }
            else
            {
                int roomId = availableRoomIds.top();
                availableRoomIds.pop();

                ++count[roomId];
                occupied.push({end, roomId});
            }
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};
