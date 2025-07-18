// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> count;

        for (const int num : nums)
            ++count[num];

        for (auto it = count.begin(); it != count.end(); ++it)
        {
            int num = it->first;
            int freq = it->second;
            if (count.find(num + 1) != count.end())
                ans = max(ans, freq + count[num + 1]);
        }

        return ans;
    }
};

// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class Solution
//  {
//  public:
//      int findLHS(vector<int> &nums)
//      {
//          int ans = 0;
//          unordered_map<int, int> count;

//         for (const int num : nums)
//             ++count[num];

//         for (const auto &[num, freq] : count)
//             if (const auto it = count.find(num + 1); it != count.cend())
//                 ans = max(ans, freq + it->second);

//         return ans;
//     }
// };