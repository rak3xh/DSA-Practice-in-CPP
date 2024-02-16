#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length() / 2; i++)
    {
        swap(str[i], str[str.length() - i - 1]);
    }
    cout << str;
}