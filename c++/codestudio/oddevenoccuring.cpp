#include <iostream>
#include <vector>
using namespace std;
int missingNumber(int n, vector<int> &arr)
{
    // Write your code here.
    int ans = 0;
    for (int i : arr)
    {
        ans = ans ^ i;
    }
    return ans;
}