#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int temp = n;
    int ans = 0;
    int i = 0;
    do
    {
        int digit = n % 10;
        n = n / 10;
        ans = (ans * 10) + digit;
        i++;
    } while (n != 0);
    cout << "the reversed numer is: " << ans;
    if (temp == ans)
    {
        cout << endl
             << "True";
    }
    else
        cout << endl
             << "false";
}
