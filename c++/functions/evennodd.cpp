#include <iostream>
using namespace std;
bool isEven(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    int num;
    cin >> num;

    if (isEven(num))
    {
        cout << endl
             << "The number is Even!!!";
    }
    else
    {
        cout << endl
             << "The number is odd!!";
    }
}