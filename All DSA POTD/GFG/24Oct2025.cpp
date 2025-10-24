#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &arr, int k)
    {
        // code here
        unordered_map<int, int> freq, end;
        for (int num : arr)
            freq[num]++;

        for (int num : arr)
        {
            if (freq[num] == 0)
                continue;
            if (end[num - 1] > 0)
            {
                end[num - 1]--, end[num]++, freq[num]--;
            }
            else
            {
                bool canStart = 1;
                for (int i = 0; i < k; ++i)
                {
                    if (freq[num + i] == 0)
                    {
                        canStart = 0;
                        break;
                    }
                }
                if (!canStart)
                    return 0;
                for (int i = 0; i < k; ++i)
                {
                    freq[num + i]--;
                }
                end[num + k - 1]++;
            }
        }

        return 1;
    }
};
