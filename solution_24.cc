struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy{0, head};
        ListNode *p = &dummy;
        while (p->next != nullptr && p->next->next != nullptr)
        {
            ListNode *p1 = p->next;
            ListNode *p2 = p->next->next;
            p1->next = p2->next;
            p2->next = p1;
            p->next = p2;
            p = p1->next;
        }
    }
};