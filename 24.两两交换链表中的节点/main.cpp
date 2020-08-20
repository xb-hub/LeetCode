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
    ListNode *swapPairs(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)    return head;
        if(head == nullptr) return nullptr;
        ListNode *l = new ListNode(0);
        ListNode * ans = l;
        while(head != nullptr && head->next != nullptr)
        {
            l->next = head->next;
            head->next = head->next->next;
            l->next->next = head;

            head = head->next;
            l = l->next->next;
        }
        return ans->next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    head->next = n1;
    ListNode *n2 = new ListNode(3);
    n1->next = n2;
    ListNode *n3 = new ListNode(4);
    n2->next = n3;
    Solution solution;
    ListNode *h = solution.swapPairs(head);
    while(h != nullptr)
    {
        cout << h->val << "->";
        h = h->next;
    }
}