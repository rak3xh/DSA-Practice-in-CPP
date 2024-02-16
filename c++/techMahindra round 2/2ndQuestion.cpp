#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findEmployeesWithinRange(std::vector<int> &distances, int start, int end)
{
    std::vector<int> employeesWithinRange;

    std::sort(distances.begin(), distances.end());

    auto startIt = std::lower_bound(distances.begin(), distances.end(), start);
    auto endIt = std::upper_bound(distances.begin(), distances.end(), end);

    for (auto it = startIt; it != endIt; ++it)
    {
        employeesWithinRange.push_back(*it);
    }

    return employeesWithinRange;
}

int main()
{
    int N; // Number of employees
    std::cout << "Enter the number of employees: ";
    std::cin >> N;

    std::vector<int> distances(N);
    std::cout << "Enter the distances of employees from the company: ";
    for (int i = 0; i < N; ++i)
    {
        std::cin >> distances[i];
    }

    int start, end;
    std::cout << "Enter the start distance: ";
    std::cin >> start;
    std::cout << "Enter the end distance: ";
    std::cin >> end;

    std::vector<int> employeesWithinRange = findEmployeesWithinRange(distances, start, end);

    std::cout << "Employees within the range are: ";
    for (int distance : employeesWithinRange)
    {
        std::cout << distance << " ";
    }
    std::cout << std::endl;

    return 0;
}