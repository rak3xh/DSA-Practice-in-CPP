#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int n, i = 2;
    int sum = 0;
    cout << "Enter the maximum range of the number: ";
    cin >> n;
    while (i <= n)
    {
        sum = sum + i;
        i = i + 2;
    }
    cout << "The sum of all the even numbers between 0 - " << n << " is : " << sum;
    getch();
}