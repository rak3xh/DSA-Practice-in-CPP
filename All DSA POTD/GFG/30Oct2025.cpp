#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis,
             int r, int c)
    {

        int n = grid.size();
        int m = grid[0].size();

        if (r < 0 || c < 0 || r >= n || c >= m)
            return;
        if (grid[r][c] == 'X' || vis[r][c] == true)
            return;

        // grid[r][c]='X';
        vis[r][c] = true;

        dfs(grid, vis, r - 1, c);
        dfs(grid, vis, r + 1, c);
        dfs(grid, vis, r, c - 1);
        dfs(grid, vis, r, c + 1);
    }
    void fill(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 'O' and vis[0][i] == false)
            {
                dfs(grid, vis, 0, i);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (grid[n - 1][i] == 'O' and vis[n - 1][i] == false)
            {
                dfs(grid, vis, n - 1, i);
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (grid[i][0] == 'O' and vis[i][0] == false)
            {
                dfs(grid, vis, i, 0);
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (grid[i][m - 1] == 'O' and vis[i][m - 1] == false)
            {
                dfs(grid, vis, i, m - 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'O' && !vis[i][j])
                    grid[i][j] = 'X';
            }
        }
    }
};