#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubarrSum(vector<int> &arr, int a, int b)
    {
        // code here
        int n = arr.size();
        int ans = INT_MIN;
        deque<int> q;

        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + arr[i - 1];

        for (int i = a; i <= n; i++)
        {
            while (!q.empty() && q.front() + b < i)
                q.pop_front();
            while (!q.empty() && pre[q.back()] > pre[i - a])
                q.pop_back();
            q.push_back(i - a);

            ans = max(ans, pre[i] - pre[q.front()]);
        }

        return ans;
    }
};

// Not Optimal solution
//  class Solution
//  {
//  public:
//      void findSubArr(vector<int> &arr, int a, int b, vector<vector<int>> &subArrays)
//      {
//          int n = arr.size();
//          for (int i = 0; i < n; i++)
//          {
//              vector<int> temp;
//              for (int j = i; j < n; j++)
//              {
//                  temp.push_back(arr[j]);
//                  if (temp.size() >= a && temp.size() <= b)
//                  {
//                      subArrays.push_back(temp);
//                  }
//              }
//          }
//      }
//      int maxSubarrSum(vector<int> &arr, int a, int b)
//      {
//          // code here
//          vector<vector<int>> subArrays;
//          findSubArr(arr, a, b, subArrays);

//         vector<int> arrSum;
//         for (auto i : subArrays)
//         {
//             int sum = 0;
//             for (auto j : i)
//             {
//                 sum = sum + j;
//             }
//             arrSum.push_back(sum);
//         }
//         sort(arrSum.begin(), arrSum.end());
//         int n = arrSum.size();
//         return arrSum[n - 1];
//     }
// };