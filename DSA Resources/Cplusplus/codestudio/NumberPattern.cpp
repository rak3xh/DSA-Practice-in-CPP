#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printPattern(int n)
{
    // Wite your coder here.

    int num1 = 1;
    vector<vector<int>> ans;
    vector<int> ans1;
    int num2 = ((n * n) + 1);
    for (int i = 1; i <= n; i++)
    {

        ans1.clear();
        for (int j = 0; j < n - i + 1; j++)
        {
            ans1.push_back(num1);
            num1++;
        }
        int temp = num2 - 1;
        for (int k = 0; k < n - i + 1; k++)
        {
            ans1.push_back(num2);
            num2++;
        }
        ans.push_back(ans1);
        num2 = temp - (n - i - 1);
    }
    return ans;
}