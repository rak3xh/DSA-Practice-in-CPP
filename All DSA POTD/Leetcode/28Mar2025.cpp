#include <bits/stdc++.h>
using namespace std;

struct IndexedQuery
{
    int queryIndex;
    int query;
};

struct T
{
    int i;
    int j;
    int val;
};

class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(queries.size());

        auto compare = [](const T &a, const T &b)
        { return a.val > b.val; };
        priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        minHeap.push({0, 0, grid[0][0]});
        seen[0][0] = true;
        int accumulate = 0;

        vector<IndexedQuery> indexedQueries = getIndexedQueries(queries);
        for (const auto &indexedQuery : indexedQueries)
        {
            int queryIndex = indexedQuery.queryIndex;
            int query = indexedQuery.query;

            while (!minHeap.empty())
            {
                T top = minHeap.top();
                if (top.val >= query)
                {
                    break;
                }
                minHeap.pop();
                ++accumulate;
                for (const auto &dir : kDirs)
                {
                    int x = top.i + dir[0];
                    int y = top.j + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || seen[x][y])
                    {
                        continue;
                    }
                    minHeap.push({x, y, grid[x][y]});
                    seen[x][y] = true;
                }
            }
            ans[queryIndex] = accumulate;
        }

        return ans;
    }

private:
    vector<IndexedQuery> getIndexedQueries(const vector<int> &queries)
    {
        vector<IndexedQuery> indexedQueries;
        for (int i = 0; i < queries.size(); ++i)
        {
            indexedQueries.push_back({i, queries[i]});
        }
        sort(indexedQueries.begin(), indexedQueries.end(), [](const IndexedQuery &a, const IndexedQuery &b)
             { return a.query < b.query; });
        return indexedQueries;
    }
};
// C++ 20 Solution
/*
struct IndexedQuery
{
    int queryIndex;
    int query;
};

struct T
{
    int i;
    int j;
    int val; // grid[i][j]
};

class Solution
{
    public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int m = grid.size();
        const int n = grid[0].size();
        vector<int> ans(queries.size());
        auto compare = [](const T &a, const T &b)
        { return a.val > b.val; };
        priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
        vector<vector<bool>> seen(m, vector<bool>(n));

        minHeap.emplace(0, 0, grid[0][0]);
        seen[0][0] = true;
        int accumulate = 0;

        for (const auto &[queryIndex, query] : getIndexedQueries(queries))
        {
            while (!minHeap.empty())
            {
                const auto [i, j, val] = minHeap.top();
                minHeap.pop();
                if (val >= query)
                {
                    // The smallest neighbor is still larger than `query`, so no need to
                    // keep exploring. Re-push (i, j, grid[i][j]) back to the `minHeap`.
                    minHeap.emplace(i, j, val);
                    break;
                }
                ++accumulate;
                for (const auto &[dx, dy] : kDirs)
                {
                    const int x = i + dx;
                    const int y = j + dy;
                    if (x < 0 || x == m || y < 0 || y == n)
                    continue;
                    if (seen[x][y])
                    continue;
                    minHeap.emplace(x, y, grid[x][y]);
                    seen[x][y] = true;
                }
            }
            ans[queryIndex] = accumulate;
        }

        return ans;
    }

    private:
    vector<IndexedQuery> getIndexedQueries(const vector<int> &queries)
    {
        vector<IndexedQuery> indexedQueries;
        for (int i = 0; i < queries.size(); ++i)
        indexedQueries.push_back({i, queries[i]});
        ranges::sort(
            indexedQueries, ranges::less{},
            [](const IndexedQuery &indexedQuery)
            { return indexedQuery.query; });
            return indexedQueries;
        }
    };
    */