#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> luckyNumbers (vector<vector<int>>& matrix) {
//         for (const vector<int>& row : matrix) {
//       const int minIndex = distance(row.begin(), ranges::min_element(row));
//       if (row[minIndex] == maxNumOfColumn(matrix, minIndex))
//         return {row[minIndex]};
//     }
//     return {};
//   }

//  private:
//   int maxNumOfColumn(const vector<vector<int>>& matrix, int j) {
//     int res = 0;
//     for (int i = 0; i < matrix.size(); ++i)
//       res = max(res, matrix[i][j]);
//     return res; 
//     }
// };
// int main()
// {
//     int a[20][20];
//     int lucky = 0;
//     cout << "Enter the number of element of matrix";
//     int m, n;
//     cin >> m >> n;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (a[i][j] > a[i][j + 1])
//             {
//                 lucky = a[i][j];
//                 cout << "lucky";
//             }
//             j++;
//         }
//     }
//     cout << lucky;
// }