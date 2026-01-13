#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <stdexcept>

using namespace std;

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        // Compute half of the total area
        double halfArea = accumulate(
                              squares.begin(), squares.end(), 0.0,
                              [](double sum, const vector<int> &square)
                              {
                                  return sum + static_cast<long long>(square[2]) * square[2];
                              }) /
                          2.0;

        // Events: (y, isStart, length)
        vector<tuple<int, bool, int>> events;

        for (const vector<int> &square : squares)
        {
            int y = square[1];
            int l = square[2];
            events.emplace_back(y, true, l);      // start
            events.emplace_back(y + l, false, l); // end
        }

        // Sort events by y
        sort(events.begin(), events.end());

        double area = 0.0;
        int width = 0;
        int prevY = 0;

        for (size_t i = 0; i < events.size(); ++i)
        {
            int y = get<0>(events[i]);
            bool isStart = get<1>(events[i]);
            int l = get<2>(events[i]);

            double areaGain = static_cast<double>(width) * (y - prevY);

            if (area + areaGain >= halfArea)
            {
                return prevY + (halfArea - area) / width;
            }

            area += areaGain;
            width += isStart ? l : -l;
            prevY = y;
        }

        throw runtime_error("No separating line found");
    }
};
