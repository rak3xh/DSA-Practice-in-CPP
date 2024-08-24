#include <iostream>
#include <iomanip>
using namespace std;
double power(double x, int n)
{
    double ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= x;
    }
    return ans;
}
int main()
{
    double num, answer;
    cout << "Enter the Number whose power is to be checked: ";
    cin >> num;
    int pow;
    cout << endl
         << "Enter the power of the number";
    cin >> pow;
    answer = power(num, pow);
    cout << "The Power of " << num << "^" << pow << " is: " << answer;
}