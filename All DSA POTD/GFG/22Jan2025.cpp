#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

Node *buildList()
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
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 1; i < size; i++)
    {
        val = arr[i];
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
    Node *reverseList(Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *prev = NULL;
        Node *forward = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            forward = curr->next;

            curr->next = prev;

            prev = curr;

            curr = forward;
        }

        return prev;
    }

public:
    Node *addTwoLists(Node *num1, Node *num2)
    {

        Node *head1 = reverseList(num1);
        Node *head2 = reverseList(num2);

        int carry = 0;

        Node *dummy = new Node(-1);
        Node *head = dummy;

        while (head1 && head2)
        {
            int val1 = head1->data;
            int val2 = head2->data;

            int sum = val1 + val2 + carry;

            carry = sum / 10;

            int num = sum % 10;

            Node *temp = new Node(num);

            dummy->next = temp;

            dummy = temp;

            head1 = head1->next;
            head2 = head2->next;
        }

        while (head1)
        {
            int val1 = head1->data;

            int sum = val1 + carry;

            carry = sum / 10;

            int num = sum % 10;

            Node *temp = new Node(num);

            dummy->next = temp;

            dummy = temp;

            head1 = head1->next;
        }

        while (head2)
        {
            int val2 = head2->data;

            int sum = val2 + carry;

            carry = sum / 10;

            int num = sum % 10;

            Node *temp = new Node(num);

            dummy->next = temp;

            dummy = temp;

            head2 = head2->next;
        }

        if (carry != 0)
        {
            Node *temp = new Node(carry);

            dummy->next = temp;

            dummy = temp;
        }

        head = head->next;

        Node *newHead = reverseList(head);

        while (newHead->data == 0)
        {
            newHead = newHead->next;
        }

        return newHead;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--)
    {
        Node *num1 = buildList();
        Node *num2 = buildList();
        Solution ob;
        Node *res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}
