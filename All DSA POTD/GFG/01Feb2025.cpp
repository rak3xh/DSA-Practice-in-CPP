#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool solve(int i, int j, int k, string &word, vector<vector<bool>> &visited, vector<vector<char>> &mat)
    {
        if (k == word.size())
        {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || mat[i][j] != word[k])
        {
            return false;
        }

        visited[i][j] = true;

        for (auto &dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (solve(new_i, new_j, k + 1, word, visited, mat))
            {
                return true;
            }
        }

        visited[i][j] = false;
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word)
    {
        // Code here
        m = mat.size();
        n = mat[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == word[0])
                {
                    if (solve(i, j, 0, word, visited, mat))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
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
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}