#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        const int mx = *max_element(nums.begin(), nums.end());
        if (mx <= 0)
            return mx;
        unordered_set<int> numsSet(nums.begin(), nums.end());
        return accumulate(numsSet.begin(), numsSet.end(), 0,
                          [](int acc, int num)
                          { return acc + max(0, num); });
    }
};
// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class Solution
//  {
//  public:
//      int maxSum(vector<int> &nums)
//      {
//          const int mx = ranges::max(nums);
//          if (mx <= 0)
//              return mx;
//          unordered_set<int> numsSet(nums.begin(), nums.end());
//          return accumulate(numsSet.begin(), numsSet.end(), 0,
//                            [](int acc, int num)
//                            { return acc + max(0, num); });
//      }
//  };