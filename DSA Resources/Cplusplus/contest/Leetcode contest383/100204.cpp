#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int minimumTimeToInitialState(string word, int k)
	{
		vector<char> s(word.begin(), word.end());
		int n = s.size();
		std::vector<int> z = Z(s);
		int ct = 0;
		for (int i = k; i < n; i += k)
		{
			ct++;
			if (z[i] == n - i)
			{
				return ct;
			}
		}
		return ct + 1;
	}

	std::vector<int> Z(std::vector<char> &str)
	{
		int n = str.size();
		std::vector<int> z(n, 0);
		if (n == 0)
			return z;
		z[0] = n;
		int l = 0, r = 0;
		for (int i = 1; i < n; i++)
		{
			if (i > r)
			{
				l = r = i;
				while (r < n && str[r - l] == str[r])
					r++;
				z[i] = r - l;
				r--;
			}
			else
			{
				if (z[i - l] < r - i + 1)
				{
					z[i] = z[i - l];
				}
				else
				{
					l = i;
					while (r < n && str[r - l] == str[r])
						r++;
					z[i] = r - l;
					r--;
				}
			}
		}
		return z;
	}
};