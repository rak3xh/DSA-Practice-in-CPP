#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int X[4] = {1, 0, -1, 0};
    int Y[4] = {0, -1, 0, 1};

    bool solve(vector<vector<char>> &mat, int index, int i, int j, vector<vector<int>> &vis, int m, int n, string &word)
    {

        if (index == word.size())
            return true;

        vis[i][j] = 1;
        bool ans = false;

        for (int k = 0; k < 4; k++)
        {
            int newx = i + X[k];
            int newy = j + Y[k];

            if (newx >= 0 && newx < m && newy >= 0 && newy < n && mat[newx][newy] == word[index] && vis[newx][newy] == 0)
            {
                ans = ans || solve(mat, index + 1, newx, newy, vis, m, n, word);
            }
        }
        vis[i][j] = 0;
        return ans;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word)
    {
        // Code here
        char ch = word[0];
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> points;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == ch)
                {
                    points.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < points.size(); i++)
        {
            int u = points[i].first;
            int v = points[i].second;
            vector<vector<int>> vis(m, vector<int>(n, 0));
            bool ans = solve(mat, 1, u, v, vis, m, n, word);

            if (ans)
                return true;
        }

        return false;
    }
};