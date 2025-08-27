#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countTriangles(vector<int> &arr)
    {
        // code here
        int len = arr.size();
        if (len < 3)
            return 0;
        int res = 0;
        sort(arr.begin(), arr.end());
        for (int k = len - 1; k >= 2; k--)
        {
            int i = 0, j = k - 1;
            while (i < j)
            {
                if ((arr[i] + arr[j]) > arr[k])
                {
                    res += j - i;
                    j--;
                }
                else
                    i++;
            }
        }
        return res;
    }
};
