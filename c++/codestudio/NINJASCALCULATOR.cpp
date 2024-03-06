#include <bits/stdc++.h>
using namespace std;
string toBinaryCalculator(double num)
{
    if (num >= 1 || num <= 0)
        return "ERROR";

    string ans;
    double x = 0.5;
    ans.append("0.");
    while (num > 0)
    {
        if (ans.length() >= 32)
            return "ERROR";

        if (num >= x)
        {
            ans.append("1");
            num = num - x;
        }
        else
        {
            ans.append("0");
        }
        x /= 2;
    }
    return ans;
}
