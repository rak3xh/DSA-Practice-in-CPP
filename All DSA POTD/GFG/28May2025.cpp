#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool ValidCorner(vector<vector<int>> &mat)
    {
        // code here
        vector<vector<int>> vec;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    for (int k = j + 1; k < mat[i].size(); k++)
                    {
                        if (mat[i][k] == 1)
                        {
                            vec.push_back({i, j, k});
                        }
                    }
                }
            }
        }
        for (int k = 0; k < vec.size(); k++)
        {
            int i = vec[k][0];
            int j1 = vec[k][1];
            int j2 = vec[k][2];
            for (int idx = i + 1; idx < mat.size(); idx++)
            {
                if (mat[idx][j1] == 1 && mat[idx][j2] == 1)
                    return true;
            }
        }
        return false;
    }
};