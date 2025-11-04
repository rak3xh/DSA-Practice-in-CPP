#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        vector<int> ans;
        long windowSum = 0;
        unordered_map<int, int> count;
        multiset<pair<int, int>> top; // top x elements
        multiset<pair<int, int>> bot; // rest of elements

        // Lambda to update the count and windowSum
        auto update = [&](int num, int freq)
        {
            if (count[num] > 0)
            { // Clean up the old count
                auto it = bot.find(make_pair(count[num], num));
                if (it != bot.end())
                {
                    bot.erase(it);
                }
                else
                {
                    it = top.find(make_pair(count[num], num));
                    if (it != top.end())
                    {
                        top.erase(it);
                        windowSum -= (long)num * count[num];
                    }
                }
            }
            count[num] += freq;
            if (count[num] > 0)
                bot.insert(make_pair(count[num], num));
        };

        for (int i = 0; i < (int)nums.size(); ++i)
        {
            update(nums[i], 1);
            if (i >= k)
                update(nums[i - k], -1);

            // Move elements from bottom to top if needed
            while (!bot.empty() && top.size() < (size_t)x)
            {
                auto it = bot.end();
                --it;
                int countB = it->first;
                int b = it->second;
                bot.erase(it);
                top.insert(make_pair(countB, b));
                windowSum += (long)b * countB;
            }

            // Swap bottom and top elements if needed
            while (!bot.empty() && !top.empty() && *bot.rbegin() > *top.begin())
            {
                auto itB = bot.end();
                --itB;
                int countB = itB->first;
                int b = itB->second;

                auto itT = top.begin();
                int countT = itT->first;
                int t = itT->second;

                bot.erase(itB);
                top.erase(itT);

                bot.insert(make_pair(countT, t));
                top.insert(make_pair(countB, b));

                windowSum += (long)b * countB;
                windowSum -= (long)t * countT;
            }

            if (i >= k - 1)
                ans.push_back((int)windowSum);
        }

        return ans;
    }
};
