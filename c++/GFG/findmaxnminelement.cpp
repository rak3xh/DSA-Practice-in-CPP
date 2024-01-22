#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<long long, long long> getMinMax(long long a[], int n)
{
    long long max = a[0];
    long long min = a[0];
    pair<long long, long long> p;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        else if (a[i] < min)
        {
            min = a[i];
        }
    }

    p.first = min;
    p.second = max;
    return p;
}