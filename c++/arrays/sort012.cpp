#include <iostream>
using namespace std;
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void sort(int a[], int n)
{
    int i = 0, j = n - 1;
    int step = 0;
    while (i < j)
    {
        cout << "After Step " << step++ << endl;
        print(a, n);
        while (a[i] == 0 && i < j)
        {
            i++;
        }
        while (a[j] == 2 && i < j)
        {
            j--;
        }
        while (a[i] < a[j] && i < j)
        {
            i++;
            j--;
        }
        if (a[i] > a[j] && i < j)
        {
            swap(a[i], a[j]);
            i++;
        }
        else if (a[i] == a[j] && i < j)
        {
            if (a[i + 1] == 2 && i < j)
            {
                swap(a[i + 1], a[j]);
                j--;
            }
        }
    }
}
int main()
{
    int a[6] = {2, 1, 2, 0, 1, 0};
    sort(a, 6);
    cout << "\nReturning to main !!" << endl;
    print(a, 6);
}