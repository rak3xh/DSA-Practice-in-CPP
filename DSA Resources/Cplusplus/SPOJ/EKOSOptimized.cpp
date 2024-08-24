#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
bool possible(int arr[], int n, long long m, int mid)
{
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {

            sum = sum + (arr[i] - mid);
        }
    }

    if (sum >= m)
    {

        return true;
    }
    return false;
}

int check(int arr[], int n, long long m)
{
    int s = 0;
    int e = arr[n - 1];
    int answer = 0;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (possible(arr, n, m, mid))
        {

            answer = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return answer;
}

int main()
{

    int N;
    long long M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int answer = check(arr, N, M);
    cout << answer;

    return 0;
}