#include <iostream>
using namespace std;
void fibonacci(int n)
{
    int a = 0, b = 1;
    int sum = a + b;
    cout << a << " , " << b << " , ";
    for (int i = 0; i < (n - 2); i++)
    {
        cout << sum << " ,";
        a = b;
        b = sum;
        sum = a + b;
    }
}
int main()
{
    int n;
    cin >> n;
    fibonacci(n);
}