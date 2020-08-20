#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    // {
    //     if(l1 == nullptr)   return l2;
    //     if(l2 == nullptr)   return l1;
    //     ListNode *head;
    //     if(l1->val < l2->val)
    //     {
    //         head = l1;
    //         head->next = mergeTwoLists(l1->next, l2);
    //     }
    //     else
    //     {
    //         head = l2;
    //         head->next = mergeTwoLists(l1, l2->next);
    //     }
    //     return head;
    // }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(l1 == nullptr)   return l2;
        if(l2 == nullptr)   return l1;
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val < l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        return head->next;
    }
};

int main()
{
}