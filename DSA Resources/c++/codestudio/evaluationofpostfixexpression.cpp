#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll M = 1e9 + 7;

ll mod(ll a)
{
    return ((a % M) + M) % M;
}

ll add(ll a, ll b)
{
    return mod(mod(a) + mod(b));
}

ll sub(ll a, ll b)
{
    return mod(mod(a) - mod(b));
}

ll mul(ll a, ll b)
{
    return mod(mod(a) * mod(b));
}

ll bin(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }

        a = mul(a, a);
        b >>= 1;
    }

    return res;
}

ll divide(ll a, ll b)
{
    b = bin(b, M - 2);

    return mul(a, b);
}

ll op(ll a, ll b, char c)
{
    if (c == '+')
    {
        return add(a, b);
    }
    if (c == '-')
    {
        return sub(b, a);
    }

    if (c == '*')
    {
        return mul(a, b);
    }

    return divide(b, a);
}

int evaluatePostfix(string &s)
{

    stack<ll> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (isspace(s[i]))
        {
            continue;
        }

        if (isdigit(s[i]))
        {

            string temp = "";
            while (i < n && isdigit(s[i]))
            {
                temp += s[i];
                i++;
            }
            i--;

            ll number = stoll(temp);

            st.push(number);
        }
        else
        {
            char c = s[i];

            ll num1 = st.top();
            st.pop();

            ll num2 = st.top();
            st.pop();

            ll ans = op(num1, num2, c);

            st.push(ans);
        }
    }

    return mod(st.top());
}