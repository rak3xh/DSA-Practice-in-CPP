#include <iostream>
#include <vector>

void rotateMatrixClockwise(std::vector<std::vector<int>> &matrix)
{
    int N = matrix.size();
    int M = matrix[0].size();

    for (int layer = 0; layer < N / 2; ++layer)
    {
        int first = layer;
        int last = N - 1 - layer;

        for (int i = first; i < last; ++i)
        {
            int offset = i - first;
            int top = matrix[first][i];

            // Move values from left to top
            matrix[first][i] = matrix[last - offset][first];

            // Move values from bottom to left
            matrix[last - offset][first] = matrix[last][last - offset];

            // Move values from right to bottom
            matrix[last][last - offset] = matrix[i][last];

            // Move values from top to right
            matrix[i][last] = top;
        }
    }
}

void printMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> inputMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    std::cout << "Input Matrix:" << std::endl;
    printMatrix(inputMatrix);

    rotateMatrixClockwise(inputMatrix);

    std::cout << "\nOutput Matrix:" << std::endl;
    printMatrix(inputMatrix);

    return 0;
}
