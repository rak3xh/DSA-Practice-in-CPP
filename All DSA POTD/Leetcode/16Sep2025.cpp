#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // gcd implementation
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // lcm implementation
    long long lcm(long long a, long long b)
    {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> ans;

        for (int num : nums)
        {
            while (!ans.empty() && gcd(ans.back(), num) > 1)
            {
                num = (int)lcm(ans.back(), num);
                ans.pop_back();
            }
            ans.push_back(num);
        }

        return ans;
    }
};

// C++ 20 Soultion
class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> ans;

        for (int num : nums)
        {
            while (!ans.empty() && std::gcd(ans.back(), num) > 1)
                num = std::lcm(ans.back(), num), ans.pop_back();
            ans.push_back(num);
        }

        return ans;
    }
};