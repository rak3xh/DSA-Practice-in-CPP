#include <iostream>

int countTrailingZerosInFactorial(int n)
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
    }
    return count;
}

int main()
{
    int num;
    std::cout << "Enter a number to find trailing zeros in its factorial: ";
    std::cin >> num;
    int trailingZeros = countTrailingZerosInFactorial(num);
    std::cout << "The number of trailing zeros in " << num << "! is: " << trailingZeros << std::endl;
    return 0;
}