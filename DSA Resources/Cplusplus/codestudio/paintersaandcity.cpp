#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &board, int N, int A, long long time)
{
    int painters = 1;
    long long currTime = 0;

    for (int i = 0; i < N; i++)
    {
        if (board[i] > time)
        {
            return false;
        }

        if (currTime + board[i] > time)
        {
            painters++;
            currTime = board[i];
        }
        else
        {
            currTime += board[i];
        }
    }

    return painters <= A;
}

long long minTime(vector<int> &board, int N, int A, int B)
{
    long long left = *max_element(board.begin(), board.end());
    long long right = accumulate(board.begin(), board.end(), 0LL);
    long long ans = 0;
    while (left < right)
    {
        long long mid = left + (right - left) / 2;

        if (isPossible(board, N, A, mid))
        {
            ans = mid * B;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}
int main()
{
    vector<int> a{1, 10};
    int n = 2;
    int A = 2;
    int B = 5;
    long long ans = minTime(a, n, A, B);
    cout << ans;
}