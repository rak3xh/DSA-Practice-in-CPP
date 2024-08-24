#include <iostream>
using namespace std;

int occur(int a[], int n, int k)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (a[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (k > a[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}
int main()
{
    int k;
    int a[6] = {1, 2, 3, 3, 4, 5};
    cout << " The ans is\n"
         << occur(a, 6, 3);
    return 0;
}