#include <iostream>
using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    if (isPrime(n))
    {
        cout << "The number is prime";
    }
    else
        cout << "The is not prime";
}