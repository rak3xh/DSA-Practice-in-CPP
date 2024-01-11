
#include <bits/stdc++.h>
typedef std::array<int, 100> DirectoryArray;
void test_fill(DirectoryArray const &x, int expected_value)
{
    for (size_t i = 0; i < x.size(); ++i)
    {
        assert(x[i] == expected_value);
    }
}
int main()
{
    DirectoryArray directory;
    directory.fill(-1);
    test_fill(directory, -1);
    return 0;
}