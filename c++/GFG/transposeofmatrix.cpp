#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // Function to find transpose of a matrix.
    void transpose(vector<vector<int>> &matrix, int n)
    {
        vector<vector<int>> a = matrix;
        // code here
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = a[j][i];
                matrix[i][j] = temp;
            }
        }
    }
};