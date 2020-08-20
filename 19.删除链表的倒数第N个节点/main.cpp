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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if(head == nullptr || n == 0)  return nullptr;
        ListNode *fast = head, *slow = head;
        int k = 0;
        while(k < n - 2)
        {
            if(fast->next != nullptr)
            {
                fast = fast->next;
            }
            else
            {
                return nullptr;
            }
            k++;
        }
        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main()
{
    
}