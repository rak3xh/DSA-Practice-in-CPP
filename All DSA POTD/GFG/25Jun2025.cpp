#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool sameFreq(string &s)
    {
        // code here
        vector<int> v(26, 0);
        for (auto z : s)
        {
            v[z - 97]++;
        }

        unordered_map<int, int> um;
        for (auto z : v)
        {
            if (z > 0)
                um[z]++;
        }

        if (um.size() == 1)
            return true;
        if (um.size() == 2)
        {
            int k1 = -1, v1 = -1;
            int k2 = -1, v2 = -1;

            for (auto z : um)
            {
                if (k1 == -1)
                {
                    k1 = z.first;
                    v1 = z.second;
                }
                else
                {
                    k2 = z.first;
                    v2 = z.second;
                }
            }

            // cout<<k1<<" "<<v1<<endl;
            // cout<<k2<<" "<<v2<<endl;

            if (k1 < k2)
            {
                if (k1 == 1 && v1 == 1)
                    return true;
                if ((k2 - k1) == 1 && v2 == 1)
                    return true;
            }
            if (k2 < k1)
            {
                if (k2 == 1 && v2 == 1)
                    return true;
                if ((k1 - k2) == 1 && v1 == 1)
                    return true;
            }

            return false;
        }

        return false;
    }
};