#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countValid(int n, vector<int> &arr)
    {
        // code here
        bool isZero = false;
        for (auto val : arr)
        {
            if (val == 0)
            {
                isZero = true;
            }
        }
        long long total = 9 * pow(10, n - 1);
        int r = 9 - arr.size();
        long long falsy = (isZero) ? pow(10 - arr.size(), n) : r * pow(10 - arr.size(), n - 1);
        return total - falsy;
    }
};
