#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        for (int i = 0; i < 31; i++)
        {
            int ans = pow(2, i);
            if (ans == n)
            {
                return true;
            }
        }
        return false;
    }
} obj;
int main()
{
    int n;
    cin >> n;
    bool ans = obj.isPowerOfTwo(n);
    cout << ans;
}