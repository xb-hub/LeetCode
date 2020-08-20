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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *front_head = new ListNode(0), *behind_head = new ListNode(0);
        ListNode *front = front_head, *behind = behind_head;
        while(head != nullptr)
        {
            if(head->val < x)
            {
                front->next = head;
                front = front->next;
            }
            else
            {
                behind->next = head;
                behind = behind->next;
            }
            head = head->next;
        }
        front->next = behind_head->next;
        behind->next = nullptr;
        return front_head->next;
    }
};

int main()
{
    Solution solution;
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(4);
    n0->next = n1;
    ListNode *n2 = new ListNode(3);
    n1->next = n2;
    ListNode *n3 = new ListNode(2);
    n2->next = n3;
    ListNode *n4 = new ListNode(5);
    n3->next = n4;
    ListNode *n5 = new ListNode(2);
    n4->next = n5;
    ListNode *head = solution.partition(n0, 3);
    while(head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
}