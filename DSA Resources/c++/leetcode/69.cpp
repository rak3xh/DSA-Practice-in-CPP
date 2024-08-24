class Solution
{
private:
    long long int sqrt(int n)
    {
        int s = 0, e = n;
        long int mid = s + (e - s) / 2;

        long long int ans = -1;
        while (s <= e)
        {
            long long int power = mid * mid;
            if (power == n)
            {
                return mid;
            }
            else if (power < n)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        return sqrt(x);
    }
};