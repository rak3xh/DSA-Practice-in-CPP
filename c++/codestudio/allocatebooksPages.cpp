#include <iostream>
#include <vector>
using namespace std;
bool PossibleSolution(vector<int> &pages, int n, int m, int mid)
{
    int StudentCount = 1;
    int totalPages = 0;
    for (int i = 0; i < n; i++)
    {
        if (totalPages + pages[i] <= mid)
        {
            totalPages += pages[i];
        }
        else
        {
            StudentCount++;
            if (StudentCount > m || pages[i] > mid)
            {
                return false;
            }
            totalPages = pages[i];
        }
    }
    return true;
}
int AllocatePages(vector<int> &pages, int n, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pages[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (PossibleSolution(pages, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> pages{12, 34, 67, 90};
    int n = 4;
    int m = 2;
    int ans = AllocatePages(pages, n, m);
    cout << ans;
}