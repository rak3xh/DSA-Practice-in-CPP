#include <bits/stdc++.h>
using namespace std;
int f(int x, int y, int m, int n, int w, vector<vector<bool>> isVisited, vector<vector<int>> &DP)
{
    if (x == w or y == w)
        return 0;
    if (DP[x][y] != -1)
        return DP[x][y];

    vector<int> op(6, INT_MAX);
    isVisited[x][y] = true;
    // operation-1
    if (!isVisited[0][y])
    {
        op[0] = f(0, y, m, n, w, isVisited, DP);
        if (op[0] != INT_MAX)
            op[0]++;
    }

    // operation-2
    if (!isVisited[x][0])
    {
        op[1] = f(x, 0, m, n, w, isVisited, DP);
        if (op[1] != INT_MAX)
            op[1]++;
    }

    // operation-3
    if (!isVisited[m][y])
    {
        op[2] = f(m, y, m, n, w, isVisited, DP);
        if (op[2] != INT_MAX)
            op[2]++;
    }

    // operation-4
    if (!isVisited[x][n])
    {
        op[3] = f(x, n, m, n, w, isVisited, DP);
        if (op[3] != INT_MAX)
            op[3]++;
    }

    // operation-5
    int a = min(m - x, y);
    if (!isVisited[x + a][y - a])
    {
        op[4] = f(x + a, y - a, m, n, w, isVisited, DP);
        if (op[4] != INT_MAX)
            op[4]++;
    }

    // operation-6
    int b = min(x, n - y);
    if (!isVisited[x - b][y + b])
    {
        op[5] = f(x - b, y + b, m, n, w, isVisited, DP);
        if (op[5] != INT_MAX)
            op[5]++;
    }

    int minimum_op = INT_MAX;
    for (int i = 0; i < 6; i++)
        minimum_op = min(minimum_op, op[i]);
    return DP[x][y] = minimum_op;
}
int ninjaAndVessels(int m, int n, int w)
{
    vector<vector<int>> DP(m + 1, vector<int>(n + 1, -1));
    vector<vector<bool>> isVisited(m + 1, vector<bool>(n + 1, false));
    int op = f(0, 0, m, n, w, isVisited, DP);
    return op == INT_MAX ? -1 : op;
}