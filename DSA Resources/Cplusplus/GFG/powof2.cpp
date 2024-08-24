class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {

        if (n == 0)
            return false;
        return ((n == 1) || (n % 2 == 0 && isPowerofTwo(n / 2)));
    }
};