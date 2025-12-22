#include <bits/stdc++.h>
using namespace std;
// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        //
        int maxrow = -1;
        int maxone = -1;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    count += (m - j);
                    break;
                }
            }
            if (count > maxone)
            {
                maxone = max(maxone, count);
                maxrow = i;
            }
        }
        return maxrow;
    }
};