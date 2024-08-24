#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num, sum = 0, prod = 1;
    while (n != 0)
    {
        num = n % 10;
        sum += num;
        prod *= num;
        n = n / 10;
    }
    cout << (prod - sum);
}