#include <iostream>
using namespace std;
class Solution
{
private:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int reversed = 0;
        while (x > reversed)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return x == reversed || x == reversed / 10;
    }

public:
    int PalinArray(int a[], int n)
    {
        // code here
        int counter = 0, i = 0;
        while (i < n)
        {
            if (isPalindrome(a[i]))
            {
                counter++;
                i++;
                
            }
            else
            {
                i++;
            }
        }
        if (counter == n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
} obj;
int main()
{
    int n;
    cin >> n;
    int a[20];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << obj.PalinArray(a, n);
}