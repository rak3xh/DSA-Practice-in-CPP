// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        const int kMax = 100;
        vector<int> count(kMax + 1, 0);

        for (int num : nums)
            ++count[num];

        // find the maximum frequency
        int maxFreq = *max_element(count.begin(), count.end());

        // count how many elements have that frequency
        int freqCount = 0;
        for (int c : count)
            if (c == maxFreq)
                ++freqCount;

        return freqCount * maxFreq;
    }
};

// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class Solution
//  {
//  public:
//      int maxFrequencyElements(vector<int> &nums)
//      {
//          constexpr int kMax = 100;
//          vector<int> count(kMax + 1);

//         for (const int num : nums)
//             ++count[num];

//         const int maxFreq = ranges::max(count);
//         return ranges::count(count, maxFreq) * maxFreq;
//     }
// };