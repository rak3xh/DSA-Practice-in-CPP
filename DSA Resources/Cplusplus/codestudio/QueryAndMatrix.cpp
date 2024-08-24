#include <bits/stdc++.h>
using namespace std;

vector<int> query(vector<vector<int>> &mat, int m, int n, vector<string> &q)
{
    // Write your code here.
    vector<int> ans;
    for (auto temp : q)
    {
        int index = int(temp[2] - '0');
        if (temp[0] == '1')
        {
            if (temp[1] == 'R' || temp[1] == 'r')
            {
                for (int i = 0; i < n; i++)
                    mat[index][i] = 1 - mat[index][i];
            }
            else
            {
                for (int i = 0; i < m; i++)
                    mat[i][index] = 1 - mat[i][index];
            }
        }
        else
        {
            int count = 0;
            if (temp[1] == 'R' || temp[1] == 'r')
            {
                for (int i = 0; i < n; i++)
                {
                    if (mat[index][i] == 0)
                        count++;
                }
            }
            else
            {
                for (int i = 0; i < m; i++)
                {
                    if (mat[i][index] == 0)
                        count++;
                }
            }
            ans.push_back(count);
        }
    }
    return ans;
}