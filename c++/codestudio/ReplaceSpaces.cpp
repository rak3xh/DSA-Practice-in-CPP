#include <bits/stdc++.h>
using namespace std;
string replaceSpaces(string &str)
{

    string st = "";

    for (int i = 0; str[i] != '\0'; i++)
    {

        if (str[i] == ' ')
        {

            st.push_back('@');

            st.push_back('4');

            st.push_back('0');
        }
        else
        {

            st.push_back(str[i]);
        }
    }

    return st;
}
