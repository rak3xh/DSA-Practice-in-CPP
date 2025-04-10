// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<pair<int, int>> xs;
        vector<pair<int, int>> ys;

        for (const vector<int> &rectangle : rectangles)
        {
            const int startX = rectangle[0];
            const int startY = rectangle[1];
            const int endX = rectangle[2];
            const int endY = rectangle[3];
            xs.emplace_back(startX, endX);
            ys.emplace_back(startY, endY);
        }

        return max(countMerged(xs), countMerged(ys)) >= 3;
    }

private:
    int countMerged(vector<pair<int, int>> &intervals)
    {
        int count = 0;
        int prevEnd = 0;

        sort(intervals.begin(), intervals.end());

        for (size_t i = 0; i < intervals.size(); ++i)
        {
            int start = intervals[i].first;
            int eend = intervals[i].second;

            if (start < prevEnd)
            {
                prevEnd = max(prevEnd, eend);
            }
            else
            {
                prevEnd = eend;
                ++count;
            }
        }

        return count;
    }
};

// C++ 20 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<pair<int, int>> xs;
        vector<pair<int, int>> ys;

        for (const vector<int> rectangles : rectangles)
        {
            const int startX = rectangles[0];
            const int startY = rectangles[1];
            const int endX = rectangles[2];
            const int endY = rectangles[3];
            xs.emplace_back(startX, endX);
            ys.emplace_back(startY, endY);
        }

        return max(countMerged(xs), countMerged(ys)) >= 3;
    }

    private:
    int countMerged(vector<pair<int, int>> &intervals)
    {
        int count = 0;
        int prevEnd = 0;

        sort(intervals.begin(), intervals.end());

        for (const auto &[start, eend] : intervals)
        if (start < prevEnd)
        {
            prevEnd = max(prevEnd, eend);
        }
        else
        {
            prevEnd = eend;
            ++count;
        }

        return count;
    }
};
*/