#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void sort012(int *arr, int n)
{
    //   Write your code here
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