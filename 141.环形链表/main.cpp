#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)   return false;
        ListNode* fast = head->next,* slow = head;
        while(slow != fast)
        {
            if(fast->next == nullptr)    return false;
            slow = slow->next;
            fast = fast->next;
            if(fast->next != nullptr)   fast = fast->next;
        }
        return true;
    }
};