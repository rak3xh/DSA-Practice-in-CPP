#include <iostream>
using namespace std;
int getmax(int a[], int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int getmin(int a[], int n)
{
    int min = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
int main()
{
    int arr[50];
    int n;
    int max, min;
    cout << endl
         << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the Elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    max = getmax(arr, n);
    cout << "\n The maximum element is : " << max;
    min = getmin(arr, n);
    cout << "\n The minimum element is : " << min;
}