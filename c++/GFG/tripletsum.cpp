#include <iostream>
#include <algorithm>
using namespace std;
bool check(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + arr[i + 1] + arr[i + 2] == 0)
        {
            return 1;
            break;
        }
    }
    return 0;
}
int main()
{
    int a[] = {97, -27, 2, -34, 61, -39};
    int n = 6;
    cout << "Answer is : " << check(a, n);
}