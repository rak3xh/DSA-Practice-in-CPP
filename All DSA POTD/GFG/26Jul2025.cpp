#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findMajority(vector<int> &arr)
    {
        // Code here
        vector<int> ans;
        int x = floor((arr.size()) / 3);
        map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }
        for (auto ele : m)
        {
            if (ele.second > x)
                ans.push_back(ele.first);
        }
        return ans;
    }
};