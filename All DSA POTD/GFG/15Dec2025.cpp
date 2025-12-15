#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cntWays(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int tOdd = 0, tEven = 0, os = 0, es = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                tEven += arr[i];
            else
                tOdd += arr[i];
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int rOdd = tOdd - os;
            int rEven = tEven - es;

            if (i % 2 != 0)
            {
                rOdd -= arr[i];
            }
            else
                rEven -= arr[i];

            if (rEven + os == rOdd + es)
                cnt++;

            if (i % 2 == 0)
                es += arr[i];
            else
                os += arr[i];
        }
        return cnt;
    }
};