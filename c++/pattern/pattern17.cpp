#include <iostream>
using namespace std;
int main()
{
    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int j = 1;
        int num = n - i + 1;
        while (j <= i)
        {

            cout << num << " ";
            num++;
            j++;
        }
        cout << endl;
        i++;
    }
}