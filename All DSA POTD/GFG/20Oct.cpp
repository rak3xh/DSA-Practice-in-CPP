#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution
{
public:
    // function to sort a k sorted doubly linked list
    struct compare
    {
        bool operator()(DLLNode *first, DLLNode *second)
        {
            return first->data > second->data;
        }
    };
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
        // code here
        priority_queue<DLLNode *, vector<DLLNode *>, compare> pq;

        for (int i = 0; head != nullptr && i <= k; i++)
        {
            pq.push(head);
            head = head->next;
        }
        DLLNode *new_head = nullptr;
        DLLNode *curr = nullptr;
        while (pq.size())
        {
            if (new_head == nullptr)
            {
                new_head = pq.top();
                new_head->prev = nullptr;
                curr = new_head;
            }
            else
            {
                curr->next = pq.top();
                pq.top()->prev = curr;
                curr = pq.top();
            }
            pq.pop();
            if (head)
            {
                pq.push(head);
                head = head->next;
            }
        }
        curr->next = nullptr;
        return new_head;
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data)
{
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head)
{
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
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

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i)
        {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}