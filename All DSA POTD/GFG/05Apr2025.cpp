#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis, vector<pair<int, int>> &dir, int &n, int &m)
    {
        vis[i][j] = 1;

        for (auto d : dir)
        {
            int di = i + d.first;
            int dj = j + d.second;
            if (di >= 0 && dj >= 0 && di < n && dj < m && grid[di][dj] == 'L' && !vis[di][dj])
            {
                dfs(grid, di, dj, vis, dir, n, m);
            }
        }
    }
    int countIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'L' && !vis[i][j])
                {
                    cnt++;
                    dfs(grid, i, j, vis, dir, n, m);
                }
            }
        }
        return cnt;
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
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}