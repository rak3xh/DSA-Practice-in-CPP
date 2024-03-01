#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
// Validity function.
bool isValid(vector<vector<int>> &mat, int m, int n, int i, int j)
{

    // Base case.
    if (m - i < 3 || n - j < 3)
    {
        return false;
    }

    // To store distinct numbers.
    unordered_set<int> val;

    // Traverse the submatrix.
    for (int r = i; r < i + 3; ++r)
    {
        for (int c = j; c < j + 3; ++c)
        {
            val.insert(mat[r][c]);
        }
    }

    // Check if all distinct numbers are present in submatrix.
    if (val.size() != 9)
    {
        return false;
    }

    // First row sum.
    int row1 = mat[i][j] + mat[i][j + 1] + mat[i][j + 2];

    // Second row sum.
    int row2 = mat[i + 1][j] + mat[i + 1][j + 1] + mat[i + 1][j + 2];

    // Third row sum.
    int row3 = mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];

    // Check for sum of all rows.
    if ((row1 != row2) || (row1 != row3))
    {
        return false;
    }

    // Check for columns.
    int col1 = mat[i][j] + mat[i + 1][j] + mat[i + 2][j];
    int col2 = mat[i][j + 1] + mat[i + 1][j + 1] + mat[i + 2][j + 1];
    int col3 = mat[i][j + 2] + mat[i + 1][j + 2] + mat[i + 2][j + 2];

    // Check for sum of all columns.
    if ((col1 != col2) || (col1 != col3) || (row1 != col1))
    {
        return false;
    }

    // Check for diagonals.
    int diag1 = mat[i][j] + mat[i + 1][j + 1] + mat[i + 2][j + 2];
    int diag2 = mat[i][j + 2] + mat[i + 1][j + 1] + mat[i + 2][j];

    // Check for sum of all diagonals.
    if ((diag1 != diag2) || (row1 != diag1))
    {
        return false;
    }

    return true;
}

int countSqaures(int m, int n, vector<vector<int>> &mat)
{

    // Base case.
    if (m < 3 || n < 3)
    {
        return 0;
    }

    // To store the result.
    int cnt = 0;

    // Traverse the matrix.
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            // Check if valid matrix.
            if (isValid(mat, m, n, i, j))
            {

                // Increment count.
                ++cnt;
            }
        }
    }

    return cnt;
}