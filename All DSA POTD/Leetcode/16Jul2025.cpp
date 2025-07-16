// C++ 14 Solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        vector<vector<int>> dp(2, vector<int>(2, 0));

        for (const int x : nums)
        {
            for (int y = 0; y < 2; ++y)
            {
                dp[x % 2][y] = dp[y][x % 2] + 1;
            }
        }

        int result = 0;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                result = max(result, dp[i][j]);
            }
        }

        return result;
    }
};
//  C++ 20 Solution
//   #include <bits/stdc++.h>
//   using namespace std;
//   class Solution
//   {
//   public:
//       int maximumLength(vector<int> &nums)
//       {
//           vector<vector<int>> dp(2, vector<int>(2));

//         // Extend the pattern xyxyxy...xy.
//         for (const int x : nums)
//             for (int y = 0; y < 2; ++y)
//                 dp[x % 2][y] = dp[y][x % 2] + 1;

//         return accumulate(dp.begin(), dp.end(), 0,
//                           [](int acc, const vector<int> &row)
//                           {
//                               return max(acc, ranges::max(row));
//                           });
//     }
// };