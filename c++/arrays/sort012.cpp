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
void sort(int arr[], int n) // dutch national flag algorithm
{
    int low = 0;

    int high = n - 1;

    int mid = 0;

    while (mid <= high)
    {

        switch (arr[mid])
        {

        case 0:

            swap(arr[low], arr[mid]);

            low++;

            mid++;

            break;

        case 1:

            mid++;

            break;

        case 2:

            swap(arr[mid], arr[high]);

            high--;

            break;
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