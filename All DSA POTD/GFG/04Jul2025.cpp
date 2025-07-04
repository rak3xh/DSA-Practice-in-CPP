#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countAtMostK(vector<int> &arr, int k)
    {
        // code here
        map<int, int> mp;
        int l = 0, r = 0, ans = 0;
        while (r < arr.size())
        {
            mp[arr[r]]++;
            while (mp.size() > k)
            {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0)
                {
                    mp.erase(arr[l]);
                }
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
};