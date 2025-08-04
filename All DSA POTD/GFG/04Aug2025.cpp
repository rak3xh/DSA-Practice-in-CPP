#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxRectSum(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int result = INT_MIN;
        for (int start = 0; start < m; start++)
        {
            vector<int> temp(n, 0);
            for (int end = start; end < m; end++)
            {
                for (int i = 0; i < n; i++)
                {
                    temp[i] += mat[i][end];
                }
                int sum = 0;
                int maxi = INT_MIN;
                for (int i = 0; i < n; i++)
                {
                    sum += temp[i];
                    maxi = max(maxi, sum);
                    if (sum < 0)
                    {
                        sum = 0;
                    }

                    result = max(maxi, result);
                }
            }
        }
        return result;
    }
};
