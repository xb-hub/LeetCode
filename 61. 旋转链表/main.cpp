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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(head == nullptr || k == 0)   return head;
        ListNode *tmp = head, *origin_head = head, *end;
        int len = 0;
        while(tmp != nullptr)
        {
            if(tmp->next == nullptr)    end = tmp;
            tmp = tmp->next;
            len++;
        }
        k %= len;
        if(k == 0)  return head;
        int move = len - k - 1;
        while(move != 0)
        {
            head = head->next;
            move--;
        }
        ListNode *new_head = head->next;
        head->next = nullptr;
        end->next = origin_head;
        return new_head;
    }
};

int main()
{
    Solution solution;
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    n0->next = n1;
    ListNode *n2 = new ListNode(3);
    n1->next = n2;
    ListNode *n3 = new ListNode(4);
    n2->next = n3;
    ListNode *n4 = new ListNode(5);
    n3->next = n4;
    ListNode *head = solution.rotateRight(n0, 2);
    while(head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
}