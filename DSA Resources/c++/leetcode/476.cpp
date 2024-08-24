#include <iostream>
using namespace std;
class Solution
{
public:
    int bitwiseComplement(int num) // optimal solution
    {
        int mask = 1;

        while (mask < num)
            mask = (mask << 1) + 1;

        return mask ^ num;
    }
} obj;
int main()
{
    int n;
    cin >> n;
    int ans = obj.bitwiseComplement(n);
    cout << ans;
}