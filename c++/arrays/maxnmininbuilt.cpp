#include <iostream>
using namespace std;
int getmax(int a[], int n)
{
    int maxim = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        maxim = max(maxim, a[i]);
    }
    return maxim;
}
int getmin(int a[], int n)
{
    int mini = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, a[i]);
    }
    return mini;
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