// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int ans = 0;

        // Sort by x ascending, and if x is same then y descending
        sort(points.begin(), points.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // y descending
                 return a[0] < b[0];     // x ascending
             });

        for (int i = 0; i < (int)points.size(); ++i)
        {
            int maxY = INT_MIN;
            for (int j = i + 1; j < (int)points.size(); ++j)
            {
                if (points[i][1] >= points[j][1] && points[j][1] > maxY)
                {
                    ++ans;
                    maxY = points[j][1];
                }
            }
        }

        return ans;
    }
};

//  C++ 20 Solution
//   #include <bits/stdc++.h>
//   using namespace std;
//   class Solution
//   {
//   public:
//       int numberOfPairs(vector<vector<int>> &points)
//       {
//           int ans = 0;

//         ranges::sort(points, ranges::less{}, [](const vector<int> &point)
//                      {
//       const int x = point[0];
//       const int y = point[1];
//       return pair<int, int>{x, -y}; });

//         for (int i = 0; i < points.size(); ++i)
//         {
//             int maxY = INT_MIN;
//             for (int j = i + 1; j < points.size(); ++j)
//                 if (points[i][1] >= points[j][1] && points[j][1] > maxY)
//                 {
//                     ++ans;
//                     maxY = points[j][1];
//                 }
//         }

//         return ans;
//     }
// };