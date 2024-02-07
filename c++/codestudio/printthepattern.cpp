#include <bits/stdc++.h>
using namespace std;
vector<string> printPattern(int n)
{
    // Write your code here
    vector<string> store(n);
    if (n % 2 != 0)
    {

        int first = 0;
        int last = n - 1;
        int start = 1;
        while (first <= last)
        {
            string str1 = "";
            string str2 = "";
            for (int i = 1; i <= n; i++)
            {
                str1 += to_string(start++) + " ";
            }

            store[first] = str1;
            if (first != last)
            {
                for (int j = 1; j <= n; j++)
                {
                    str2 += to_string(start++) + " ";
                }

                store[last] = str2;
            }
            first++;
            last--;
        }
    }

    else
    {
        int first = 0;
        int last = n - 1;
        int start = 1;
        while (first < last)
        {
            string str1 = "";
            string str2 = "";
            for (int i = 1; i <= n; i++)
            {
                str1 += to_string(start++) + " ";
            }

            store[first] = str1;

            for (int j = 1; j <= n; j++)
            {
                str2 += to_string(start++) + " ";
            }

            store[last] = str2;

            first++;
            last--;
        }
    }
    return store;
}