#include <iostream>
#include <regex>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string compareFrac(string str)
    {

        // Code here
        int i = 0;
        string op1 = "", op2 = "", op3 = "", op4 = "";
        while (str[i] != '/')
        {
            op1 += str[i];
            i++;
        }
        i++;
        while (str[i] != ',')
        {
            op2 += str[i];
            i++;
        }
        i++;
        i++;
        while (str[i] != '/')
        {
            op3 += str[i];
            i++;
        }
        i++;
        while (str[i] != '\0')
        {
            op4 += str[i];
            i++;
        }
        if (stod(op1) / stod(op2) > stod(op3) / stod(op4))
        {
            return op1 + "/" + op2;
        }
        else if (stod(op1) / stod(op2) < stod(op3) / stod(op4))
        {
            return op3 + "/" + op4;
        }
        return "equal";
    }
};

//{ Driver Code Starts.

int main()
{
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}
