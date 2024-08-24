#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void convertToWave(int n, vector<int> &arr)
{

    // Your code here
    int s = 0;
    while (s < n - 1)
    {
        swap(arr[s], arr[s + 1]);
        s += 2;
    }
}
int main()
{
    vector<int> a{2, 4, 7, 8, 9, 10};
    convertToWave(6, a);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
}