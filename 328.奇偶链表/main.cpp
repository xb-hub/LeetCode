#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if(head == nullptr) return nullptr;
        ListNode *evenhead = head->next, *oddnode = head, *evennode = evenhead;
        while (evennode != nullptr && evennode->next != nullptr)
        {
            oddnode->next = evennode->next;
            oddnode = oddnode->next;
            evennode->next = oddnode->next;
            evennode = evennode->next;
        }
        oddnode->next = evenhead;
        return head;
    }
};

int main()
{
    Solution solution;
    ListNode *n0 = new ListNode(2);
    ListNode *n1 = new ListNode(1);
    n0->next = n1;
    ListNode *n2 = new ListNode(3);
    n1->next = n2;
    ListNode *n3 = new ListNode(5);
    n2->next = n3;
    ListNode *n4 = new ListNode(6);
    n3->next = n4;
    ListNode *n5 = new ListNode(4);
    n4->next = n5;
    // ListNode *n6 = new ListNode(7);
    // n5->next = n6;
    ListNode *head = solution.oddEvenList(n0);
    while(head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
}