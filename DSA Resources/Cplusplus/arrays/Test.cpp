#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarySearch(vector<int> &arr, int k)
    {
        int n = arr.size();
        int start = 0, end = n - 1;
        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (arr[mid] == k)
            {
                return mid;
            }
            else if (k > arr[mid])
            {
                start = mid + 1;
            }
            else
                end = mid - 1;

            mid = start + (end - start) / 2;
        }
        return -1;
    }
};
int main()
{
    vector<int> arr;
    int n, input, target;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
    cin >> target;
    Solution obj;
    int index = obj.binarySearch(arr, target);
    if (index >= 0)
    {
        cout << "Found at Index: " << index;
    }
    else
        cout << "Not Found!!!";
}