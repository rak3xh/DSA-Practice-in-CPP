#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> mp = {{10000000, "crore "}, {100000, "lakh "}, {1000, "thousand "}, {100, "hundred "}, {90, "ninety "}, {80, "eighty "}, {70, "seventy "}, {60, "sixty "}, {50, "fifty "}, {40, "forty "}, {30, "thirty "}, {20, "twenty "}, {19, "nineteen "}, {18, "eighteen "}, {17, "seventeen "}, {16, "sixteen "}, {15, "fifteen "}, {14, "fourteen "}, {13, "thirteen "}, {12, "twelve "}, {11, "eleven "}, {10, "ten "}, {9, "nine "}, {8, "eight "}, {7, "seven "}, {6, "six "}, {5, "five "}, {4, "four "}, {3, "three "}, {2, "two "}, {1, "one "}};

string solve(int num)
{

    if (num == 0)
    {

        return "Zero ";
    }

    for (auto it : mp)
    {

        if (num >= it.first)
        {

            string a = "";

            if (num >= 100)
            {

                a = solve(num / it.first);
            }

            string b = it.second;

            string c = "";

            if (num % it.first != 0)
            {

                if (num > 100 && num % it.first < 100)
                {

                    c = "and " + solve(num % it.first);
                }
                else
                {

                    c = solve(num % it.first);
                }
            }

            return a + b + c;
        }
    }

    return "Zero";
}

string handleAll(int n)

{

    string ans = solve(n);

    // ans.pop_back();

    return ans;
}