// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> mem(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        dfs(grid, 0, 0, /*cost=*/0, q, mem);

        for (int cost = 1; !q.empty(); ++cost)
        {
            for (int sz = q.size(); sz > 0; --sz)
            {
                auto cell = q.front();
                int i = cell.first, j = cell.second;
                q.pop();
                for (const auto &dir : dirs)
                    dfs(grid, i + dir[0], j + dir[1], cost, q, mem);
            }
        }

        return mem[m - 1][n - 1];
    }

private:
    static const int dirs[4][2];

    void dfs(const vector<vector<int>> &grid, int i, int j, int cost,
             queue<pair<int, int>> &q, vector<vector<int>> &mem)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (mem[i][j] != -1)
            return;

        mem[i][j] = cost;
        q.emplace(i, j);
        const auto &dir = dirs[grid[i][j] - 1];
        dfs(grid, i + dir[0], j + dir[1], cost, q, mem);
    }
};
const int Solution::dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// C++20 Solution

// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     int minCost(vector<vector<int>> &grid)
//     {
//         const int m = grid.size();
//         const int n = grid[0].size();
//         vector<vector<int>> mem(m, vector<int>(n, -1));
//         queue<pair<int, int>> q;

//         dfs(grid, 0, 0, /*cost=*/0, q, mem);

//         for (int cost = 1; !q.empty(); ++cost)
//             for (int sz = q.size(); sz > 0; --sz)
//             {
//                 const auto [i, j] = q.front();
//                 q.pop();
//                 for (const auto &[dx, dy] : dirs)
//                     dfs(grid, i + dx, j + dy, cost, q, mem);
//             }

//         return mem.back().back();
//     }

// private:
//     static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

//     void dfs(const vector<vector<int>> &grid, int i, int j, int cost,
//              queue<pair<int, int>> &q, vector<vector<int>> &mem)
//     {
//         if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
//             return;
//         if (mem[i][j] != -1)
//             return;

//         mem[i][j] = cost;
//         q.emplace(i, j);
//         const auto &[dx, dy] = dirs[grid[i][j] - 1];
//         dfs(grid, i + dx, j + dy, cost, q, mem);
//     }
// };