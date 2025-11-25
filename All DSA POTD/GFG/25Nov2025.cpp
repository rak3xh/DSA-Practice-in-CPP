#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarrayXor(vector<int> &arr)
    {
        // code here
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; ++i)
        {
            int cnt = (i + 1) * (n - i);
            if (cnt & 1)
                res ^= arr[i];
        }

        return res;
    }
};