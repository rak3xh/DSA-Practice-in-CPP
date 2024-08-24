#include <bits/stdc++.h>
using namespace std;
void multiply(vector<vector<int>> &mat, vector<vector<int>> &res)
{
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                res[i][j] += mat[i][k] * mat[k][j];
            }
        }
    }
}

// Function to check idempotent
// property of matrix.
bool matrixGame(vector<vector<int>> &mat)
{
    int n = mat.size();

    // Calculate multiplication of matrix
    // with itself and store it into res.
    vector<vector<int>> res(n, vector<int>(n));

    // Matrix multiplication
    multiply(mat, res);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Check for equality bewtween the matrices
            if (mat[i][j] != res[i][j])
            {
                return false;
            }
        }
    }

    // Return true otherwise
    return true;
}