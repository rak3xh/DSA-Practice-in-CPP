#include <iostream>
using namespace std;
int ap(int n)
{
    int result = (3 * n) + 7;
    return result;
}
int main()
{
    int n;
    cin >> n;
    int ans = ap(n);
    cout << "The answer : " << ans;
}