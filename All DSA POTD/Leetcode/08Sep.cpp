#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k);
        const int length = getLength(head);
        const int subLength = length / k;
        int remainder = length % k;

        ListNode *prev = nullptr;
        ListNode *root = head;

        for (int i = 0; i < k; ++i, --remainder)
        {
            ans[i] = head;
            for (int j = 0; j < subLength + (remainder > 0); ++j)
            {
                prev = head;
                head = head->next;
            }
            if (prev != nullptr)
                prev->next = nullptr;
        }

        return ans;
    }

private:
    int getLength(ListNode *head)
    {
        int length = 0;
        for (ListNode *curr = head; curr; curr = curr->next)
            ++length;
        return length;
    }
};