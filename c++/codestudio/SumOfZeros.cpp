#include <bits/stdc++.h>
using namespace std;
int coverageOfMatrix(vector<vector<int>> &mat)
{
    // Write your code here.
    int n = mat.size();

    int m = mat[0].size();

    int sum = 0;

    int n_arr = n + 2;

    int m_arr = m + 2;

    int arr[n_arr][m_arr];

    for (int i = 0; i < n_arr; i++)
    {

        for (int j = 0; j < m_arr; j++)
        {

            arr[i][j] = -1;
        }
    }

    for (int i = 1; i < n_arr - 1; i++)
    {

        for (int j = 1; j < m_arr - 1; j++)
        {

            arr[i][j] = mat[i - 1][j - 1];
        }
    }

    for (int i = 1; i < n_arr - 1; i++)
    {

        for (int j = 1; j < m_arr - 1; j++)
        {

            if (arr[i][j] == 0)
            {

                if (arr[i - 1][j] == 1)
                {
                    sum += 1;
                }

                if (arr[i + 1][j] == 1)
                {
                    sum += 1;
                }

                if (arr[i][j - 1] == 1)
                {
                    sum += 1;
                }

                if (arr[i][j + 1] == 1)
                {
                    sum += 1;
                }
            }
        }
    }

    return sum;
}
