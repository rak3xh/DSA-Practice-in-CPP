#include <bits/stdc++.h>
using namespace std;

class BIT
{
    int n, m;

    vector<vector<int>> value; // storing the value of the matrix,
    vector<vector<int>> tree;  // storing the sum in Binary indexed tree;

public:
    BIT(vector<vector<int>> matrix)
    {
        n = matrix.size();
        m = (n == 0) ? 0 : matrix[0].size();

        value.resize(n + 1, vector<int>(m + 1));
        tree.resize(n + 1, vector<int>(m + 1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                update(i + 1, j + 1, matrix[i][j]);
            }
        }

        // print(value);
        // print(tree);
    }

    void print(vector<vector<int>> &matrix)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void update(int row, int col, int val)
    {
        // this delta needs to be changed in tree;
        int delta = val - value[row][col];

        value[row][col] = val;

        for (int i = row; i <= n; i += i & (-i))
        {
            for (int j = col; j <= m; j += (j & (-j)))
            {
                tree[i][j] += delta;
            }
        }
    }

    int sum(int row, int col)
    {
        int ret = 0;

        for (int i = row; i > 0; i -= (i & -i))
        {
            for (int j = col; j > 0; j -= (j & (-j)))
            {
                ret += tree[i][j];
            }
        }
        return ret;
    };
};

vector<int> matrixRangeSum(vector<vector<int>> &grid, vector<vector<int>> &queries)
{
    BIT tree(grid);

    vector<int> ret;
    for (int i = 0; i < queries.size(); i++)
    {
        int type = queries[i][0];

        if (type == 1)
        {
            int x1 = queries[i][1];
            int y1 = queries[i][2];
            int x2 = queries[i][3];
            int y2 = queries[i][4];

            x1++;
            x2++;
            y1++;
            y2++;

            int ans = tree.sum(x2, y2) - tree.sum(x2, y1 - 1) - tree.sum(x1 - 1, y2) + tree.sum(x1 - 1, y1 - 1);

            ret.push_back(ans);
        }
        else
        {
            int x = queries[i][1];
            int y = queries[i][2];
            int val = queries[i][3];

            tree.update(x + 1, y + 1, val);
        }
    }

    return ret;
}
