#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 1 or n <= 0)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    Node *primeList(Node *head)
    {
        // code here
        Node *root = head;
        while (head != NULL)
        {
            int temp = head->val;

            if (isPrime(temp))
            {
                head = head->next;
                continue;
            }
            else
            {
                int temp2 = temp;
                while (!isPrime(temp) and !isPrime(temp2))
                {
                    temp++;
                    temp2--;
                }

                if (isPrime(temp) and isPrime(temp2))
                {
                    head->val = min(temp, temp2);
                }
                else if (isPrime(temp2))
                {
                    head->val = temp2;
                }
                else
                {
                    head->val = temp;
                }

                head = head->next;
            }
        }
        return root;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        if (arr.empty())
        {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}