#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long aVeryBigSum(vector<long> ar)
{
    long long int sum = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        sum = sum + ar[i];
    }
    return sum;
}