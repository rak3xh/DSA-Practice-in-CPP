#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int count = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        cout << str[i];
    }
}