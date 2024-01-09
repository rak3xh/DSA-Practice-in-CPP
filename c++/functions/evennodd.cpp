#include <iostream>
using namespace std;
bool isEven(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    int num;
    cin >> num;
    bool ans = isEven(num);
    cout << ans;
}