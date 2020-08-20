#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if(m == 1)
        {
            if(n == 1)
            {
                return head;
            }
            ListNode *tmp = reverseBetween(head, m - 1, n - 1);
            head->next->next = head;
            head
        }
        m--;
    }
};

int main()
{
}