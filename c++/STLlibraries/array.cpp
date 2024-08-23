#include <iostream>
#include <array>
using namespace std;
int main()
{
    int basic[4] = {1, 2, 3, 4};       // basic array
    array<int, 5> a = {1, 2, 3, 4, 5}; // stl array same as basic static array but support some functions
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Element at second index:" << a.at(2) << endl;                    // at(index) use
    cout << "Check whether the array is empty or not: " << a.empty() << endl; // it will return a boolean variable to check whether the array is empty or not
    array<int, 0> arr;
    cout << "Check whether the array is empty or not: " << arr.empty() << endl;
    cout << "First Element:" << a.front() << endl; // First element of the array
    cout << "Last Element:" << a.back() << endl;   // Last element of the array

    // T.C-> every operation is O(1)
    // T.C-> Traversing is O(1)
}