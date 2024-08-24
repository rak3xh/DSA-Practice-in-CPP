#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int n = x;
        long long rev = 0;
        if (x < 0)
            return false;
        while (x > 0)
        {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }
        if (rev == n)
            return true;
        return false;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    bool answer = obj.isPalindrome(n);
    cout << answer;
}