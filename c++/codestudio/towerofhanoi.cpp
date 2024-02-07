#include <bits/stdc++.h>
using namespace std;
void towerOfHanoiUtil(int n, int source, int destination, int auxiliary, std::vector<std::vector<int>> &steps)
{

    if (n == 1)
    {

        steps.push_back({source, destination});

        return;
    }

    towerOfHanoiUtil(n - 1, source, auxiliary, destination, steps);

    steps.push_back({source, destination});

    towerOfHanoiUtil(n - 1, auxiliary, destination, source, steps);
}
vector<vector<int>> towerOfHanoi(int n)
{
    //    Write your code here.
    vector<vector<int>> steps;

    towerOfHanoiUtil(n, 1, 3, 2, steps);

    return steps;
}