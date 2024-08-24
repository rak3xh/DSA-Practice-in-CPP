#include <iostream>
using namespace std;
int SetPeice(int a)
{
    int count = 0;
    while (a != 0)
    {
        if (a & 1)
        {
            count++;
        }
        a >>= 1;
    }
    return count;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int ans1 = SetPeice(a);
    int ans2 = SetPeice(b);
    int ans = ans1 + ans2;
    cout << "Number of 1 is : " << ans;
}