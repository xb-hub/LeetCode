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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA == nullptr || headB == nullptr)    return nullptr;
        ListNode *tmpA = headA, *tmpB = headB;
        while(tmpA != tmpB)
        {
            tmpA = tmpA == nullptr ? headB : tmpA->next;
            tmpB = tmpB == nullptr ? headA : tmpB->next;
        }
        return tmpB;
    }
};

int main()
{
    return 0;
}