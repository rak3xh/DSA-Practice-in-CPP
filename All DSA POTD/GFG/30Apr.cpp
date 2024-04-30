#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to add two numbers represented by linked list.
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *forward = NULL;

        while (curr)
        {
            forward = curr->next;
            curr->next = prev;

            prev = curr;
            curr = forward;
        }

        return prev;
    }
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        // code here
        Node *rnum1 = reverse(num1);
        Node *rnum2 = reverse(num2);

        Node *ans = new Node(-1);
        Node *temp1 = rnum1;
        Node *temp2 = rnum2;
        Node *anstemp = ans;
        int sum = 0;
        int carry = 0;

        while (temp1 || temp2 || carry)
        {
            sum = 0;
            if (temp1)
            {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if (temp2)
            {
                sum += temp2->data;
                temp2 = temp2->next;
            }

            sum += carry;

            carry = sum / 10;
            anstemp->next = new Node(sum % 10);
            anstemp = anstemp->next;
        }

        ans = reverse(ans->next);

        while (ans->data == 0 && ans->next)
        {
            ans = ans->next;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *num1 = buildList(n);

        cin >> m;
        Node *num2 = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}