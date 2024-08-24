#include <iostream>
using namespace std;
int main()
{
    int arr[50];
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "The sum is : " << sum;
}