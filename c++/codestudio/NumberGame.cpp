#include <bits/stdc++.h>
using namespace std;

string gameWinner(vector<int> &arr, int n)
{

    int max = *std::max_element(arr.begin(), arr.end());

    int rem = max - n;

    if (rem % 2 != 1)
    {

        return "Bob";
    }
    else
    {

        return "Alice";
    }
}