#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>> &matrix)
    {
        // Code here
        vector<int> ans(2);
        int i = 0, j = 0, dir = 0; // dir = 0 means starting direction

        while ((i >= 0 && i < n) && (j >= 0 && j < m))
        {
            if (dir == 0)
            { // 1st direction
                if (matrix[i][j] == 1)
                { // direction change
                    matrix[i][j] = 0;
                    i++;
                    dir = 1;
                }
                else // go forward
                    j++;
            }
            else if (dir == 1)
            { // 2nd direction
                if (matrix[i][j] == 1)
                {
                    matrix[i][j] = 0;
                    j--;
                    dir = 2;
                }
                else
                    i++;
            }
            else if (dir == 2)
            { // 3rd direction
                if (matrix[i][j] == 1)
                {
                    matrix[i][j] = 0;
                    i--;
                    dir = 3;
                }
                else
                    j--;
            }
            else
            { // 4th direction
                if (matrix[i][j] == 1)
                {
                    matrix[i][j] = 0;
                    j++;
                    dir = 0;
                }
                else
                    i--;
            }
        }
        // if value goes out of range
        if (i < 0)
            i = 0;
        else if (i >= n)
            i = n - 1;
        if (j < 0)
            j = 0;
        else if (j >= m)
            j = m - 1;

        ans[0] = i;
        ans[1] = j;

        return ans;
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
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}