#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCandy(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i + 1] < arr[i])
            {
                right[i] = right[i + 1] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += max(left[i], right[i]);
        }
        return res;
    }
};
