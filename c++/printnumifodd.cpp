#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cout << "Enter the number between which it has to be printed (0-n)";
    cin >> n;
    for (i = 1; i <= n; (i++))
    {
        cout << i << " ";
        i = i + 1;
    }
    return 0;
}