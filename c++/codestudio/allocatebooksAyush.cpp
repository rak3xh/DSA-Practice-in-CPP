#include <iostream>
#include <vector>
using namespace std;
bool ispossible(int n, int m, vector<int> time, long long int mid)
{

    long long int totaltime = 0;

    long long int days = 1;

    for (long long int i = 0; i < m; i++)
    {

        if (totaltime + time[i] <= mid)
        {

            totaltime += time[i];
        }

        else
        {

            days++;

            if (days > n || time[i] > mid)
            {

                return false;
            }

            totaltime = time[i];
        }
    }

    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    if (n > m)
    {

        return -1;
    }

    long long int s = 0;

    long long int sum = 0;

    for (long long int i = 0; i < m; i++)
    {

        sum += time[i];
    }

    long long int e = sum;

    long long int mid = s + ((e - s) / 2);

    long long int ans = -1;

    while (s <= e)
    {

        if (ispossible(n, m, time, mid))
        {

            ans = mid;

            e = mid - 1;
        }

        else
        {

            s = mid + 1;
        }

        mid = s + ((e - s) / 2);
    }

    return ans;
}
int main()
{
    vector<int> time{2, 2, 3, 3, 4, 4, 1};
    int n = 3;
    int m = 5;
    long long int ans = ayushGivesNinjatest(n, m, time);
    cout << ans;
}