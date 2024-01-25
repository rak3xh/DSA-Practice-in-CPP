#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> termsOfAP(int x)
{
    // Write your code here.
    int j = 1;

    vector<int> ans;

    int count = 0;

    while (count < x)
    {

        int p = (3 * j) + 2;

        if (p % 4 != 0)
        {

            ans.push_back(p);

            j++;

            count++;
        }
        else
        {

            j++;
        }
    }

    return ans;
}
int main()
{
    int x;
    cin >> x;
    vector<int> ans = termsOfAP(x);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}