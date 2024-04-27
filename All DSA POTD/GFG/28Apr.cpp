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
/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution
{
public:
    Node *deleteMid(Node *head)
    {
        // Your Code Here
        if (head == NULL)
            return NULL;

        Node *slow = head;
        Node *fast = head;
        Node *slowprev = head;

        while (slow != NULL && fast != NULL)
        { // to find the mid

            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        while (slowprev->next != slow)
        { // another loop that takes slowprev at the back of mid(slow)
            slowprev = slowprev->next;
        }

        slowprev->next = slow->next; // make the link
        delete (slow);               // break the link

        return head;
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution obj;
        head = obj.deleteMid(head);
        printList(head);
    }
    return 0;
}
