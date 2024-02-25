#include <bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int> &arr, int n)
{

    // Write your code here.

    vector<int> answer;

    for (int i = 1; i < n; i++)

    {

        answer.push_back(arr[i]); //[2 ,3,4,5,]
    }

    answer.push_back(arr[0]);

    return answer;
}
int main()
{
}