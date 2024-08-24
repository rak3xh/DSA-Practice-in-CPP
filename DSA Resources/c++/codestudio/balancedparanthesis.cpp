#include <iostream>
#include <vector>
#include <string>

void backtrack(std::vector<std::string> &result, std::string &s, int left, int right, int N)
{
    if (s.size() == 2 * N)
    {
        result.push_back(s);
        return;
    }

    if (left < N)
    {
        s.push_back('(');
        backtrack(result, s, left + 1, right, N);
        s.pop_back();
    }

    if (right < left)
    {
        s.push_back(')');
        backtrack(result, s, left, right + 1, N);
        s.pop_back();
    }
}

std::vector<std::string> generateParentheses(int N)
{
    std::vector<std::string> result;
    std::string s;
    backtrack(result, s, 0, 0, N);
    return result;
}

int main()
{
    int N = 4;
    std::vector<std::string> sequences = generateParentheses(N);

    for (const auto &seq : sequences)
    {
        std::cout << seq << std::endl;
    }

    return 0;
}
