#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int diagonalDifference(vector<vector<int>> arr)
{
    int n = arr.size();
    int leftSum = 0;
    int rightSum = 0;
    for (int i = 0; i < n; i++)
    {
        leftSum += arr[i][i];
        rightSum += arr[i][n - 1 - i];
    }
    return abs(leftSum - rightSum);
}