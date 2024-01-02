#include <iostream>
using namespace std;
int main()
{
    int n, i, sum = 0;
    cout << "enter the range:";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "The sun of first " << n << " numbers are: " << sum;
    return 0;
}