#include <bits/stdc++.h>
using namespace std;
int middleOfThree(int x, int y, int z)
{
    // Write your code here
    int sum = x + y + z;
    int maxVal = max(x, max(y, z));
    int minVal = min(x, min(y, z));
    int middle = sum - maxVal - minVal;
    return middle;
}