#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        // Your code here
        Node *t1 = new Node(-1), *t2 = new Node(-1);
        Node *h1 = t1, *h2 = t2;
        while (head)
        {
            if (k)
            {
                t1->next = head;
                t1 = t1->next;
                k--;
            }
            else
            {
                t2->next = head;
                t2 = t2->next;
            }
            head = head->next;
            t1->next = nullptr;
            t2->next = nullptr;
        }
        t2->next = h1->next;
        return h2->next;
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

        // Read numbers from the input line
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Node *head = nullptr;

        // Check if the array is empty
        if (!arr.empty())
        {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i)
            {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}