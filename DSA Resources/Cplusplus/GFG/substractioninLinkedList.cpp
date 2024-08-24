#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *pre = NULL;
        while (curr != NULL)
        {
            Node *age = curr->next;
            curr->next = pre;
            pre = curr;
            curr = age;
        }
        return pre;
    }

    int len(Node *head)
    {
        Node *curr = head;
        int l = 0;
        while (curr != NULL && curr->data == 0)
            curr = curr->next;
        while (curr != NULL)
        {
            l++;
            curr = curr->next;
        }
        return l;
    }

    Node *subLinkedList(Node *head1, Node *head2)
    {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        int l1 = len(head1);
        int l2 = len(head2);
        Node *temp1;
        Node *temp2;
        if (l1 > l2)
        {
            temp1 = reverse(head1);
            temp2 = reverse(head2);
        }
        else if (l2 > l1)
        {
            temp2 = reverse(head1);
            temp1 = reverse(head2);
        }
        else
        {
            while (head1 != NULL && head1->data == 0)
                head1 = head1->next;
            while (head2 != NULL && head2->data == 0)
                head2 = head2->next;
            while (head1 != NULL && head2 != NULL && head1->data == head2->data)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            if (head1 != NULL && head2 != NULL && head1->data > head2->data)
            {
                temp1 = reverse(head1);
                temp2 = reverse(head2);
            }
            else if (head1 != NULL && head2 != NULL && head1->data < head2->data)
            {
                temp1 = reverse(head2);
                temp2 = reverse(head1);
            }
            else
            {
                temp1 = head1;
                temp2 = head2;
            }
        }
        int count = 0;
        LinkedList *ans = new LinkedList();
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data - count >= temp2->data)
            {
                ans->insert(temp1->data - count - temp2->data);
                count = 0;
            }
            else
            {
                ans->insert((temp1->data) + 10 - count - temp2->data);
                count = 1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1 != NULL)
        {
            if (count > 0)
            {
                if (temp1->data - count < 0)
                {
                    temp1->data = temp1->data + 10 - count;
                    count = 1;
                }
                else
                {
                    temp1->data = temp1->data - count;
                    count = 0;
                }
            }
            ans->insert(temp1->data);
            temp1 = temp1->next;
        }
        if (ans->head == NULL)
            ans->insert(0);
        Node *jj = reverse(ans->head);
        while (jj != NULL && jj->data == 0)
            jj = jj->next;
        if (jj == NULL)
        {
            return ans->head;
        }
        return jj;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node *n)
{
    while (n)
    {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1, l2;
        cin >> l1;
        for (int j = 0; j < n; ++j)
        {
            int x = (l1[j] - '0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin >> l2;
        for (int j = 0; j < m; ++j)
        {
            int x = (l2[j] - '0');
            LL2.insert(x);
        }

        Solution ob;
        Node *res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}