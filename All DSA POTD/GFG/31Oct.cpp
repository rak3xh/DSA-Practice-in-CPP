#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *getNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution
{
public:
    Node *sortedInsert(Node *head, int x)
    {
        // Code here
        Node *temp = head;
        int count = 0, count1 = 0;

        // Count the number of nodes in the list
        while (temp != NULL)
        {
            count1++;
            temp = temp->next;
        }

        // Reset temp to head
        temp = head;

        // Traverse to find the correct insertion point
        while (temp != NULL && temp->data < x)
        {
            temp = temp->next;
            count++;
        }

        // Insert at the beginning
        if (count == 0)
        {
            Node *start = new Node();
            start->data = x;
            start->next = NULL;
            start->prev = NULL;
            start->next = temp;
            if (temp != NULL)
                temp->prev = start;
            head = start;
        }
        // Insert at the end
        else if (count == count1)
        {
            Node *last = new Node();
            last->data = x;
            last->next = NULL;
            last->prev = NULL;
            temp = head;
            while (temp->next != NULL)
                temp = temp->next; // Find the last node
            temp->next = last;
            last->prev = temp;
        }
        // Insert in the middle
        else
        {
            Node *curr = new Node();
            curr->data = x;
            curr->next = NULL;
            curr->prev = NULL;
            Node *ahead = temp;
            temp = temp->prev;
            temp->next = curr;
            curr->prev = temp;
            curr->next = ahead;
            ahead->prev = curr;
        }

        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--)
    {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x)
        {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x)
        {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}