#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void increment(int *a, int *b)
{
    int sum = (*a) + (*b);
    int diff;
    cout << sum;
    if ((*b) > (*a))
    {
        diff = (*b) - (*a);
    }
    else
    {
        diff = (*a) - (*b);
    }
    cout << endl
         << diff;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b;
    cin >> a >> b;
    increment(&a, &b);

    return 0;
}
