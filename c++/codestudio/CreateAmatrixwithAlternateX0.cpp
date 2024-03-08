#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<char>> constructMatrix(int n, int m)
{ // Initialize the matrix with all '0's
    vector<vector<char>> ans(n, vector<char>(m, '0'));

    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    bool a = true;

    while (top <= bottom && left <= right)
    {
        if (a)
        {
            for (int i = left; i <= right; i++)
            {
                ans[top][i] = 'X';
                ans[bottom][i] = 'X';
            }
            top++;
            bottom--;

            for (int i = top; i <= bottom; i++)
            {
                ans[i][left] = 'X';
                ans[i][right] = 'X';
            }
            left++;
            right--;
        }
        else
        {
            for (int i = left; i <= right; i++)
            {
                ans[top][i] = '0';
                ans[bottom][i] = '0';
            }
            top++;
            bottom--;

            for (int i = top; i <= bottom; i++)
            {
                ans[i][left] = '0';
                ans[i][right] = '0';
            }
            left++;
            right--;
        }

        a = !a;
    }

    return ans;
}