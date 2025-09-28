#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        // code here
        map<int, int> mp;
        vector<int> ans;
        int n = arr.size();
        int startingIndex = -1;
        int maxSize = 0;

        int i = 0;
        int j = 0;
        mp[arr[0]]++;

        while (j < n)
        {
            auto first = mp.begin();
            auto last = prev(mp.end());

            int minElement = first->first;
            int maxElement = last->first;

            if ((maxElement - minElement) <= x)
            {
                if ((j - i + 1) > maxSize)
                {
                    maxSize = j - i + 1;
                    startingIndex = i;
                }
                j++;
                if (j < n)
                {
                    mp[arr[j]]++;
                }
            }
            else
            {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0)
                {
                    mp.erase(arr[i]);
                }
                i++;
            }
        }

        for (int p = startingIndex; p < (startingIndex + maxSize); p++)
        {
            ans.push_back(arr[p]);
        }
        return ans;
    }
};