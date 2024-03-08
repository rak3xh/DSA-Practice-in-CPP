#include <bits/stdc++.h>

using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>> &arr)

{

    int sf = startFuel;

    int n = arr.size();

    int ans = 0;

    int i = 0;

    if (target <= startFuel)

        return 0;

    priority_queue<int> pq;

    while (sf < target)

    {

        while (i < n && arr[i][0] <= sf)

        {

            pq.push(arr[i][1]);

            i++;
        }

        if (pq.empty())

            return -1;

        int mx = pq.top();

        pq.pop();

        sf += mx;

        ans++;
    }

    return ans;
}
