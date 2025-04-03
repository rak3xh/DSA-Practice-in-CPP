#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int orangesRotting(vector<vector<int>> &mat)
    {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, pair<int, int>>> q;

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                {
                    q.push({0, {i, j}});
                    vis[i][j] = true;
                }
                if (mat[i][j] == 1)
                    cnt++;
            }
        }
        int time = 0, cf = 0;
        while (!q.empty())
        {
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            time = fmax(time, t);
            q.pop();
            for (int i = 0; i < dirs.size(); ++i)
            {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 1)
                {
                    q.push({t + 1, {nr, nc}});
                    vis[nr][nc] = true;
                    cf++;
                }
            }
        }
        return (cf != cnt) ? -1 : time;
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
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}