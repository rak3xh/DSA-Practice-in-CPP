// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        auto it = max_element(dimensions.begin(), dimensions.end(),
                              [](const vector<int> &a, const vector<int> &b)
                              {
                                  int diagA = a[0] * a[0] + a[1] * a[1];
                                  int diagB = b[0] * b[0] + b[1] * b[1];
                                  if (diagA == diagB)
                                      return a[0] * a[1] < b[0] * b[1];
                                  return diagA < diagB;
                              });

        return (*it)[0] * (*it)[1];
    }
};

// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class Solution
//  {
//  public:
//      int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
//      {
//          const vector<int> maxDimension = *ranges::max_element(
//              dimensions, [](const vector<int> &a, const vector<int> &b)
//              { return (a[0] * a[0] + a[1] * a[1] == b[0] * b[0] + b[1] * b[1])
//                           ? (a[0] * a[1] < b[0] * b[1])
//                           : (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]); });
//          return maxDimension[0] * maxDimension[1];
//      }
//  };