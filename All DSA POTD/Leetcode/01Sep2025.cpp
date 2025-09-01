// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<tuple<double, int, int>> maxHeap;

        for (const vector<int> &c : classes)
        {
            int pass = c[0];
            int total = c[1];
            maxHeap.emplace(extraPassRatio(pass, total), pass, total);
        }

        for (int i = 0; i < extraStudents; ++i)
        {
            auto top = maxHeap.top();
            maxHeap.pop();
            double gain = extraPassRatio(get<1>(top) + 1, get<2>(top) + 1);
            maxHeap.emplace(gain, get<1>(top) + 1, get<2>(top) + 1);
        }

        double ratioSum = 0;

        while (!maxHeap.empty())
        {
            auto top = maxHeap.top();
            maxHeap.pop();
            int pass = get<1>(top);
            int total = get<2>(top);
            ratioSum += pass / static_cast<double>(total);
        }

        return ratioSum / classes.size();
    }

private:
    // Returns the extra pass ratio if a brilliant student joins.
    double extraPassRatio(int pass, int total)
    {
        return (pass + 1) / static_cast<double>(total + 1) -
               pass / static_cast<double>(total);
    }
};

// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class Solution
//  {
//  public:
//      double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
//      {
//          priority_queue<tuple<double, int, int>> maxHeap;

//         for (const vector<int> &c : classes)
//         {
//             const int pass = c[0];
//             const int total = c[1];
//             maxHeap.emplace(extraPassRatio(pass, total), pass, total);
//         }

//         for (int i = 0; i < extraStudents; ++i)
//         {
//             const auto [_, pass, total] = maxHeap.top();
//             maxHeap.pop();
//             maxHeap.emplace(extraPassRatio(pass + 1, total + 1), pass + 1, total + 1);
//         }

//         double ratioSum = 0;

//         while (!maxHeap.empty())
//         {
//             const auto [_, pass, total] = maxHeap.top();
//             maxHeap.pop();
//             ratioSum += pass / static_cast<double>(total);
//         }

//         return ratioSum / classes.size();
//     }

// private:
//     // Returns the extra pass ratio if a brilliant student joins.
//     double extraPassRatio(int pass, int total)
//     {
//         return (pass + 1) / static_cast<double>(total + 1) -
//                pass / static_cast<double>(total);
//     }
// };