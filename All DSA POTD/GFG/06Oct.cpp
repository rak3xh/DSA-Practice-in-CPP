#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int n, m;
    int row[8] = {0, -1, -1, -1, 0, 1, 1, 1}, col[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    // Function to find the number of islands.
    bool expand(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == '1');
    }
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        for (int k = 0; k < 8; k++)
        {
            int x = i + row[k], y = j + col[k];
            if (expand(x, y, grid, vis))
            {
                dfs(grid, x, y, vis);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        n = grid.size(), m = grid[0].size();
        int res = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, vis);
                    res++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}