#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findNearestZero(vector<vector<int>> &grid)
{
    // Write your code here.int n = grid.size(),
    int n = grid.size();
    int m = grid[0]
                .size(); // n = no. of row , m = no. of column
    queue<pair<int, int>>
        q; // to do multisource Breadth-First Search store
           // the initial index of 1s
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                q.push({i, j});
                grid[i][j] = 0; // mark the starting index as 0.
            }
            else
                grid[i][j] = INT_MAX; // rest marked as infinity.
                                      // (Not visited)
        }
    }
    int row[4] = {-1, 1, 0, 0}, col[4] = {
                                    0, 0, -1, 1}; // (up,down,left,right index from current (x,y))
    while (!q.empty())
    { // till it visit each index
        auto top = q.front();
        q.pop();
        int x = top.first // current
            ,
            y = top.second // current
            ,
            time = grid[x][y]; // time of current distance
                               // at index (x,y)
        for (int i = 0; i < 4; i++)
        {
            int newx = x + row[i], newy = y + col[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == INT_MAX)
            {                                // only for Non visited
                grid[newx][newy] = time + 1; // time of current distance
                                             // at index (x,y) + 1
                q.push(
                    {newx,
                     newy}); // storing index for getting
                             // the index of adjacent of
                             // {newx,newy}.
            }
        }
    }
    return grid; // returning the updated matrix
}