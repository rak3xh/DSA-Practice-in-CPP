#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int d, int n)
    {
        // code here
        int a[n];
        d = d % n;
        for (int i = d; i < n + d; i++)
        {
            if (i < n)
            {
                a[i - d] = arr[i];
            }
            else
            {
                a[i - d] = arr[i - n];
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = a[i];
        }
    }
} obj;
int main()
{
    int n, d, a[] = {1, 2, 3, 4, 5, 6, 7};
    n = 7;
    d = 3;
    obj.rotateArr(a, d, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}