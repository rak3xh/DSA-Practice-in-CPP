#include <bits/stdc++.h>
using namespace std;
vector<int> parseInts(string str)
{
    vector<int> ans;
    string input;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',')
        {
            ans.push_back(stoi(input));
            input = "";
        }
        else
        {
            input += str[i];
        }
    }
    ans.push_back(stoi(input));

    return ans;
}
int main()
{
    string str;
    getline(cin, str);
    vector<int> ans = parseInts(str);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}