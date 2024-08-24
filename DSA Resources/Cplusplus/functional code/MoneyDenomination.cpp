#include <iostream>
#include <conio.h> // Used for getch()
#include <cstdlib> // Used for system("cls") to clear the console screen

using namespace std;

void displayMenu()
{
    cout << "==============================\n";
    cout << " Currency Denomination Counter\n";
    cout << "==============================\n";
}

void calculateDenominations(int amount)
{
    int Rs100, Rs50, Rs20, Rs10, Rs1;

    Rs100 = Rs50 = Rs20 = Rs10 = Rs1 = 0;

    switch (1)
    {
    case 1:
        Rs100 = amount / 100;
        amount %= 100;
        cout << "No. of 100 rupees notes: " << Rs100 << endl;
    case 2:
        Rs50 = amount / 50;
        amount %= 50;
        cout << "No. of 50 rupees notes: " << Rs50 << endl;
    case 3:
        Rs20 = amount / 20;
        amount %= 20;
        cout << "No. of 20 rupees notes: " << Rs20 << endl;
    case 4:
        Rs10 = amount / 10;
        amount %= 10;
        cout << "No. of 10 rupees notes: " << Rs10 << endl;
    case 5:
        Rs1 = amount;
        cout << "No. of 1 rupee coins: " << Rs1 << endl;
        break;
    default:
        cout << "The above denomination is best!!!" << endl;
    }
}

int main()
{
    char choice;

    do
    {
        system("cls"); // Clear the console screen
        displayMenu();

        int amount;
        cout << "Enter the total amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount! Please enter a positive value." << endl;
        }
        else
        {
            calculateDenominations(amount);
        }

        cout << "\nDo you want to enter another amount? (y/n): ";
        choice = _getch(); // Get user input without pressing Enter

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the Currency Denomination Counter!" << endl;
    _getch(); // Pause before exiting

    return 0;
}
