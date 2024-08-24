#include <bits/stdc++.h>
using namespace std;
vector<int> k_stack(int L, int N, int Q, vector<vector<int>> &queries)
{
    vector<int> result;
    vector<int> top(N, 0);
    vector<int> stacks(L, 0);

    for (int i = 0; i < Q; i++)
    {
        int operation = queries[i][0];

        if (operation == 1)
        { // PUSH operation
            int stackNum = queries[i][1] - 1;
            int value = queries[i][2];

            if (top[stackNum] < L / N)
            {
                int index = stackNum * (L / N) + top[stackNum];
                stacks[index] = value;
                top[stackNum]++;
                result.push_back(0); // Push successful
            }
            else
            {
                result.push_back(0); // Stack overflow
            }
        }
        else if (operation == 2)
        { // POP operation
            int stackNum = queries[i][1] - 1;

            if (top[stackNum] > 0)
            {
                top[stackNum]--;
                int index = stackNum * (L / N) + top[stackNum];
                result.push_back(stacks[index]);
            }
            else
            {
                result.push_back(-1); // Stack underflow
            }
        }
    }

    return result;
}