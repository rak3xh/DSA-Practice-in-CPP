#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> PP;
class Solution
{
public:
    string matrixChainOrder(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<vector<PP>> t(n, vector<PP>(n, {"", -1}));

        PP ans = solve(arr, 0, n - 1, t);
        return ans.first;
    }

    PP solve(vector<int> &arr, int i, int j, vector<vector<PP>> &t)
    {
        if (i + 1 == j)
        {
            string tmp = "";
            tmp.push_back((char)('A' + i));
            return t[i][j] = {tmp, 0};
        }

        if (t[i][j].second != -1)
            return t[i][j];

        int result = INT_MAX;
        string str;

        for (int k = i + 1; k < j; k++)
        {
            auto left = solve(arr, i, k, t);
            auto right = solve(arr, k, j, t);
            int curr = left.second + right.second + (arr[i] * arr[k] * arr[j]);
            if (result > curr)
            {
                result = curr;
                str = "(" + left.first + right.first + ")";
            }
        }

        return t[i][j] = {str, result};
    }
};