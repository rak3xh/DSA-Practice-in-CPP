#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int catchThieves(vector<char> &arr, int k)
    {
        // Code here
        int n = arr.size();
        int ans = 0;
        int T = 0;
        int P = 0;

        while (T < n && P < n)
        {
            if (arr[P] != 'P')
                P++;
            else
            {

                if (arr[T] == 'T')
                {

                    if (abs(P - T) <= k)
                    {
                        T++;
                        ans++;
                        P++;
                    }
                    else
                    {
                        if (T < P)
                            T++;
                        else
                            P++;
                    }
                }
                else
                {
                    T++;
                }
            }
        }

        return ans;
    }
};