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
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

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
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        int countNine = 0, totalCount = 1, tempCount = 0, liveCount = 1;
        Node *left = head;
        while (left->next != NULL)
        {
            if (left->data == 9)
                countNine++;
            else
                countNine = 0;
            left = left->next;
            totalCount++;
        }
        if (left->data != 9)
        {
            left->data = left->data + 1;
            return head;
        }
        countNine++;
        if (countNine == totalCount)
        {
            Node *newNode = new Node(1);
            newNode->next = head;
            head = newNode;
            left = head->next;
            while (left != NULL)
            {
                left->data = 0;
                left = left->next;
            }
            return head;
        }
        left = head;
        tempCount = totalCount - countNine;
        while (left != NULL)
        {
            //   cout<<countNine<<" -> "<<totalCount<<" -> "<<tempCount<<" -> "<<liveCount<<endl;
            if (liveCount == tempCount)
            {
                //   cout<<"left -> "<<left->data<<" "<<liveCount<<" "<<tempCount<<endl;
                left->data = left->data + 1;
                left = left->next;
            }
            else if (liveCount > tempCount)
            {
                left->data = 0;
                left = left->next;
            }
            else
                left = left->next;
            liveCount++;
        }
        return head;
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
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
