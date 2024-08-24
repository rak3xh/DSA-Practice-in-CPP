#include <bits/stdc++.h>
using namespace std;
int hotelBookings(vector<string> queries)
{
    // Write your codes here.
    int cnt = 0;

    int n = queries.size();

    for (int i = 0; i < n; i++)

    {

        if (queries[i][0] == '+')

            cnt++;
    }

    return cnt++;
}
