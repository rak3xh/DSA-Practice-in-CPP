#include <iostream>
#include <conio.h>
using namespace std;
void main()
{
    int amount;
    cout << "enter the total amount:";
    cin >> amount;
    int Rs100, Rs50, Rs20, Rs1;
    switch (1)
    {
    case 1:
    {
        Rs100 = amount / 100;
        amount %= 100;
        cout << endl
             << "No. of 100 rupees note is: " << Rs100;
    }
    case 2:
    {
        Rs50 = amount / 50;
        amount %= 50;
        cout << endl
             << "No. of 50 rupees note is: " << Rs50;
    }
    case 3:
    {
        Rs20 = amount / 20;
        amount %= 20;
        cout << endl
             << "No. of 20 rupees note is: " << Rs20;
    }
    case 4:
    {
        Rs1 = amount / 1;
        amount %= 1;
        cout << endl
             << "No. of 1 rupees note is: " << Rs1;
    }
    default:
        cout << endl
             << "The above denomination is best!!!";
    }
    getch();
}