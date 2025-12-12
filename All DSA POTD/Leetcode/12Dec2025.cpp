#include <bits/stdc++.h>
using namespace std;

struct OfflineUser
{
    int returnTimestamp;
    int userId;
};

// Custom comparator for min-heap
struct CompareOfflineUser
{
    bool operator()(const OfflineUser &a, const OfflineUser &b) const
    {
        return a.returnTimestamp > b.returnTimestamp; // min-heap
    }
};

class Solution
{
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {

        vector<int> ans(numberOfUsers, 0);
        vector<int> online(numberOfUsers, true);

        priority_queue<OfflineUser, vector<OfflineUser>, CompareOfflineUser> offlineQueue;
        int allMentionsCount = 0;

        // sort(events, comparator)
        sort(events.begin(), events.end(),
             [](const vector<string> &a, const vector<string> &b)
             {
                 int ta = stoi(a[1]);
                 int tb = stoi(b[1]);
                 if (ta != tb)
                     return ta < tb;

                 // Reverse lexicographic order for event type (MESSAGE vs OFFLINE)
                 // In original code: -eventType
                 return a[0] > b[0];
             });

        for (const vector<string> &event : events)
        {
            string eventType = event[0];
            int timestamp = stoi(event[1]);

            // Bring users back online
            while (!offlineQueue.empty() &&
                   offlineQueue.top().returnTimestamp <= timestamp)
            {
                online[offlineQueue.top().userId] = true;
                offlineQueue.pop();
            }

            if (eventType == "MESSAGE")
            {

                string mentionsString = event[2];

                if (mentionsString == "ALL")
                {
                    ++allMentionsCount;
                }
                else if (mentionsString == "HERE")
                {
                    for (int userId = 0; userId < numberOfUsers; ++userId)
                        if (online[userId])
                            ++ans[userId];
                }
                else
                {
                    vector<int> ids = getUserIds(mentionsString);
                    for (int userId : ids)
                        ++ans[userId];
                }
            }
            else if (eventType == "OFFLINE")
            {
                int userId = stoi(event[2]);
                online[userId] = false;

                // Return after 60 units
                offlineQueue.push({timestamp + 60, userId});
            }
        }

        // Add all "ALL" mentions to all users
        for (int userId = 0; userId < numberOfUsers; ++userId)
            ans[userId] += allMentionsCount;

        return ans;
    }

private:
    vector<int> getUserIds(const string &s)
    {
        vector<int> integers;
        istringstream iss(s);
        string id;
        while (iss >> id)
            integers.push_back(stoi(id.substr(2)));
        return integers;
    }
};
