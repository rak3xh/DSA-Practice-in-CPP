#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int s = 0, e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (arr[mid] < arr[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }
} obj;
int main()
{
    vector<int> a{3, 4, 5, 1};
    int peak = obj.peakIndexInMountainArray(a);
    cout << a[peak];
}