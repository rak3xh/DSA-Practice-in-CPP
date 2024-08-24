#include <iostream>
#include <limits.h>
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int ans = 1;
        for (int i = 0; i <= 30; i++)
        {
            if (ans == n)
            {
                return true;
            }
            if (ans < INT_MAX / 2)
                ans *= 2;
        }
        return false;
    }
} obj;
int main()
{
    int n;
    std::cin >> n;
    bool ans = obj.isPowerOfTwo(n);
    std::cout << ans;
}