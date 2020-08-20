#include <iostream>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result_List = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* res = result_List;
        int flag = 0;
        while (p != NULL || q != NULL) {
            int result_x = 0, result_y = 0;
            p == NULL ? result_x = 0 : result_x = p->val;
            q == NULL ? result_y = 0 : result_y = q->val;
            int result_val = result_x + result_y + flag;
            flag = result_val / 10;
            res->next = new ListNode(result_val % 10);
            res = res->next;
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }
        if (flag > 0) res->next = new ListNode(1);
        return result_List->next;
    }
};

int main()
{
    Solution solution;
    ListNode *l1_1 = new ListNode(2);
    ListNode *l1_2 = new ListNode(4);
    ListNode *l1_3 = new ListNode(3);
    l1_1->next = l1_2;  l1_2->next = l1_3;
    ListNode *l2_1 = new ListNode(5);
    ListNode *l2_2 = new ListNode(6);
    ListNode *l2_3 = new ListNode(4);
    l2_1->next = l2_2;  l2_2->next = l2_3;
    ListNode* head = solution.addTwoNumbers(l1_1, l2_1);
    while(head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
    delete(l1_1);   delete(l1_2);   delete(l1_3);
    delete(l2_1);   delete(l2_2);   delete(l2_3);
}
