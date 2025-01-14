#include <bits/stdc++.h>
using namespace std;
string reverseString(string &str)
{
    // Write your code here.
    string word;
    string ans;
    for (int i = str.length()-1; i <= 0; i--)
    {
        if (str[i] == ' ')
        {
            reverse(word.begin(), word.end());
            ans = ans + word;
            word = "";
        }
        word =word+ str[i];
    }
    ans = ans + word;
    return ans;
}
int main()
{
    string s = "Welcome to Coding Ninjas";
    string ans = reverseString(s);
    cout << ans;
}