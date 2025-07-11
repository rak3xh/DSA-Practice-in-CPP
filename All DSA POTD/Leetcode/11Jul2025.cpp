// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

struct T
{
    long endTime;
    int roomId;

    // Comparator moved here for easier usage in C++14
    bool operator<(const T &other) const
    {
        if (endTime == other.endTime)
            return roomId > other.roomId;
        return endTime > other.endTime;
    }
};

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> count(n);

        sort(meetings.begin(), meetings.end());

        priority_queue<T> occupied;
        priority_queue<int, vector<int>, greater<int>> availableRoomIds;

        for (int i = 0; i < n; ++i)
            availableRoomIds.push(i);

        for (const vector<int> &meeting : meetings)
        {
            int start = meeting[0];
            int end = meeting[1];

            while (!occupied.empty() && occupied.top().endTime <= start)
            {
                availableRoomIds.push(occupied.top().roomId);
                occupied.pop();
            }

            if (availableRoomIds.empty())
            {
                T top = occupied.top();
                occupied.pop();
                int roomId = top.roomId;
                ++count[roomId];
                occupied.push({top.endTime + (end - start), roomId});
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

// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  struct T
//  {
//      long endTime;
//      int roomId;
//  };

// class Solution
// {
// public:
//     int mostBooked(int n, vector<vector<int>> &meetings)
//     {
//         vector<int> count(n);

//         ranges::sort(meetings);

//         auto compare = [](const T &a, const T &b)
//         {
//             return a.endTime == b.endTime ? a.roomId > b.roomId
//                                           : a.endTime > b.endTime;
//         };
//         priority_queue<T, vector<T>, decltype(compare)> occupied(compare);
//         priority_queue<int, vector<int>, greater<>> availableRoomIds;

//         for (int i = 0; i < n; ++i)
//             availableRoomIds.push(i);

//         for (const vector<int> &meeting : meetings)
//         {
//             const int start = meeting[0];
//             const int end = meeting[1];
//             // Push meetings ending before this `meeting` in occupied to the
//             // `availableRoomsIds`.
//             while (!occupied.empty() && occupied.top().endTime <= start)
//                 availableRoomIds.push(occupied.top().roomId), occupied.pop();
//             if (availableRoomIds.empty())
//             {
//                 const auto [newStart, roomId] = occupied.top();
//                 occupied.pop();
//                 ++count[roomId];
//                 occupied.push({newStart + (end - start), roomId});
//             }
//             else
//             {
//                 const int roomId = availableRoomIds.top();
//                 availableRoomIds.pop();
//                 ++count[roomId];
//                 occupied.push({end, roomId});
//             }
//         }

//         return ranges::max_element(count) - count.begin();
//     }
// };