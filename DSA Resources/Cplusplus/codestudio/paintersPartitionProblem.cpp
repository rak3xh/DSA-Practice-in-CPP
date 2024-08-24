#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool PossibleSolution(vector<int> &boards, int k, int mid)
{
    int Paintercount = 1;
    int BoardSum = 0;
    int n = boards.size();
    for (int i = 0; i < n; i++)
    {
        if (BoardSum + boards[i] <= mid)
        {
            BoardSum += boards[i];
        }
        else
        {
            Paintercount++;
            if (Paintercount > k || boards[i] > mid)
            {
                return false;
            }
            BoardSum = boards[i];
        }
    }
    return true;
}
int PainterProblem(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    int n = boards.size();
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = 0;
    while (s <= e)
    {
        if (PossibleSolution(boards, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> a{10, 20, 30, 40};
    int k = 2;
    int ans = PainterProblem(a, k);
    cout << ans;
}