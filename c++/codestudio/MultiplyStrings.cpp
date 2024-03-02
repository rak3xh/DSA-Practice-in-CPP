#include <bits/stdc++.h>
using namespace std;
string multiplyStrings(string a, string b)
{

    int m = a.size();

    int n = b.size();

    // Create a vector to store intermediate results

    vector<int> result(m + n, 0);

    // Multiply each digit and add to the corresponding position in the result vector

    for (int i = m - 1; i >= 0; i--)
    {

        for (int j = n - 1; j >= 0; j--)
        {

            int mul = (a[i] - '0') * (b[j] - '0');

            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10; // Update the current position

            result[i + j] += sum / 10; // Carry to the next position
        }
    }

    // Convert the result vector to a string

    string product;

    for (int num : result)
    {

        if (!(product.empty() && num == 0))
        {

            product.push_back(num + '0');
        }
    }

    // Handle the case where the product is zero

    if (product.empty())
    {

        return "0";
    }

    return product;
}
