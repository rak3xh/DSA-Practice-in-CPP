#include <iostream>
using namespace std;
int main()
{
    cout << endl
         << "***************CALCULATOR****************" << endl;
    char flag = 'y';
    do
    {
        int a, b, opans1_2 = 0, opans4 = 1;
        float opans3 = 1.0;
        char op;
        cout << endl
             << "Enter the Value of the first number: " << endl;
        std::cin >> a;
        cout << "Enter the Value of the Second number: " << endl;
        std::cin >> b;
        cout << "Enter the Operation you want to do [+, -, *, /, %] : " << endl;
        std::cin >> op;
        switch (op)
        {
        case '+':
        {
            opans1_2 = a + b;
            cout << endl
                 << "The Sum of the two input numbers is :" << opans1_2 << endl;

            break;
        }
        case '-':
        {
            opans1_2 = a - b;
            cout << endl
                 << "The difference of the two input numbers is :" << opans1_2 << endl;
            break;
        }
        case '*':
        {
            opans3 = a * b;
            cout << endl
                 << "The product of the two input numbers is :" << opans3 << endl;
            break;
        }
        case '/':
        {
            if (b == 0)
            {
                cout << endl
                     << "The number cannot be divided by zero!!!" << endl;
                break;
            }
            else
            {
                opans4 = float(a) / float(b);
                cout << endl
                     << "The result of division of the two input numbers is :" << opans4 << endl;
                break;
            }
        }
        case '%':
        {
            opans3 = a % b;
            cout << endl
                 << "The remainder of the two input numbers is :" << opans3 << endl;
            break;
        }
        default:
            cout << "Enter a valid Operator!!!";
            break;
        }
        cout << "*********************************************" << endl
             << "*********************************************";
        cout << endl
             << endl
             << "Do you want to continue :";
        std::cin >> flag;
    } while ((flag == 'y') || (flag == 'Y'));
    return 0;
}