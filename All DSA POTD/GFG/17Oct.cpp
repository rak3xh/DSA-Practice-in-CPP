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

// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    // Function to split a linked list into two lists alternately
    vector<Node *> alternatingSplitList(struct Node *head)
    {
        // Your code here
        if (head == NULL || head->next == NULL)
        {
            return {head};
        }

        vector<Node *> ans;

        Node *prev = head;
        Node *curr = head->next;

        ans.push_back(prev);
        ans.push_back(curr);

        while (prev && curr)
        {
            prev->next = curr->next;
            prev = prev->next;
            if (curr->next)
            {
                curr->next = curr->next->next;
                curr = curr->next;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;

        for (int i = 1; i < arr.size(); ++i)
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node *> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}
