#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter the character to be checked : ";
    cin >> ch;
    if (ch >= 65 && ch <= 90)
    {
        cout << "The Giver character " << ch << " is Upper Case!!";
    }
    else if (ch >= 97 && ch <= 122)
    {
        cout << "The Giver character " << ch << " is Lower Case!!";
    }
    else if (ch >= 48 && ch <= 57)
    {
        cout << "The Giver character " << ch << " is Number!!";
    }
    else
    {
        cout << "The Giver character " << ch << " is Symbol!!";
    }
}