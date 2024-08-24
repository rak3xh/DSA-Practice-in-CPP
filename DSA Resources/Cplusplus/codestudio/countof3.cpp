#include <bits/stdc++.h>
using namespace std;
long long int countOf3(int x)
{
    // Write your code here.
    long long int count = 0;

    int num = 0;

    for (int i = 0; i <= x; i++)

    {

        if (i == 3)

        {

            count++;
        }

        else

        {

            num = i;

            while (num != 0)

            {

                int newNum = num % 10;

                if (newNum == 3)

                {

                    count++;
                }

                num = num / 10;
            }
        }
    }

    return count;
}
int main()
{
    int n;
    cin >> n;
    long long int ans = countOf3(n);
    cout << ans;
}