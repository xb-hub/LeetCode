#include <iostream>
#include <stack>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        while (l1 != nullptr)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s1.push(l2->val);
            l2 = l2->next;
        }
        while (!s1.empty() || !s2.empty() || )
        {
            /* code */
        }
        
    }
};

int main()
{
}