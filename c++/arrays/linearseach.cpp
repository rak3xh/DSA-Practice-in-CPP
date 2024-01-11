#include <iostream>
using namespace std;
int main()
{
    int a[50];
    int n, k, flag = 0;
    int pos;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "enter the elemnt to be searched :";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            flag = 1;
            pos = i + 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "\n"
             << "Elemnt " << k << " found at " << pos << " position !!";
    }
    else
        cout << endl
             << "Element not found !!!!";
}