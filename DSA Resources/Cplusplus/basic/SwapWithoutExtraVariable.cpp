#include <bits/stdc++.h>
using namespace std;
void swap1(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void swap2(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << "Original : " << a << " & " << b << endl;
    swap1(a, b);
    cout << "After Change using FUnction swap1() : " << a << " & " << b << endl;
    swap2(a, b);
    cout << "After Change using FUnction swap2() : " << a << " & " << b << endl;
}