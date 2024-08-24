#include <iostream>
using namespace std;
void reverse(int a[], int n, int k)
{

    for (int i = 0; i < k; i++)
    {
        int start = (n - 1);
        int next = start - 1;
        while (start > 0)
        {
            swap(a[start], a[next]);
            start--;
            next--;
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
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
    int k;
    cin >> k;
    reverse(a, n, k);
    cout << "The final rotated array is :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}