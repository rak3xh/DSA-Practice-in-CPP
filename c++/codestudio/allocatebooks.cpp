#include <iostream>
#include <vector>
using namespace std;
bool PossibleSolution(vector<int> &books, int n, int b, int mid)
{
    int studentCount = 1;
    int totalPages = 0;
    for (int i = 0; i < n; i++)
    {
        if (totalPages + books[i] < mid)
        {
            totalPages += books[i];
        }
        else
        {
            studentCount++;
            if (studentCount > b || books[i] > mid)
            {
                return false;
            }
            totalPages = books[i];
        }
    }
    return true;
}
int AllocateBooks(vector<int> &books, int n, int b)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += books[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (PossibleSolution(books, n, b, mid))
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
    vector<int> a{10, 20, 30, 40};
    int n = 4;
    int b = 2;
    int ans = AllocateBooks(a, n, b);
    cout << ans;
}