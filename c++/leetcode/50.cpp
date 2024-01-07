#include <iostream>
#include <cstdlib>
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            x = 1 / x;
        }
        long num = labs(n);
        double pow = 1;
        while (num)
        {
            if (num & 1)
            {
                pow *= x;
            }
            x *= x;
            num >>= 1;
        }
        return pow;
    }
} obj;
int main()
{
    double n, pow;
    int x;
    std::cin >> n;
    std::cin >> x;
    pow = obj.myPow(n, x);
    std::cout << pow;
}