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
    while (i < j)
    {
        while (a[i] == 0 && i < j)
        {
            i++;
        }
        while (a[j] == 1 && i < j)
        {
            j--;
        }
        if (i < j)
            swap(a[i], a[j]);
        i++;
        j--;
    }
}
int main()
{
    int a[8] = {0, 1, 0, 0, 1, 1, 1, 0};
    sort(a, 8);
    print(a, 8);
}