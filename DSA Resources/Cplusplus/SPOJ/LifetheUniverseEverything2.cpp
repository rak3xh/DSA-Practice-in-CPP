#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int a[50], n;
    cin >> n;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 42)
        {
            break;
        }
        else
        {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << endl;
    }
}