#include <iostream>
using namespace std;
void Swap(int a[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            swap(a[i], a[i + 1]);
        }
    }
    cout << endl
         << "Printing the array ..." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n, a[50];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Swap(a, n);
}