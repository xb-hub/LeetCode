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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head == nullptr) return head;
        ListNode *tmp = head, *right = head;
        while(tmp != nullptr)
        {
            ListNode *right = tmp->next;
            while(right != nullptr && tmp->val == right->val)
            {
                right = right->next;
            }
            tmp->next = right;
            tmp = right;
        }
        return head;
    }
};

int main()
{
    Solution solution;
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(1);
    n0->next = n1;
    ListNode *n2 = new ListNode(2);
    n1->next = n2;
    ListNode *n3 = new ListNode(3);
    n2->next = n3;
    ListNode *n4 = new ListNode(3);
    n3->next = n4;
    ListNode *head = solution.deleteDuplicates(n0);
    while(head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
}