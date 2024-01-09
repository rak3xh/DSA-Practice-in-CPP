#include <iostream>
using namespace std;
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int ncr(int N, int r)
{
    int answer;
    answer = (factorial(N)) / ((factorial(r)) * (factorial(N - r)));
    return answer;
}

int main()
{
    int N, r, ans;
    cin >> N >> r;
    ans = ncr(N, r);
    cout << endl
         << ans;
}