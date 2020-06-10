#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list_node(ListNode *l)
{
    while (l != nullptr)
    {
        std::cout << l->val;
        l = l->next;
    }
}

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == nullptr)
        {
            l1 = l2;
        }
        while (l1 != nullptr)
        {
            int sum = l1->val + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            l1 = l1->next;
        }
        if (carry != 0)
        {
            current->next = new ListNode(carry);
        }
        current = dummy->next;

        delete dummy;
        return current;
    }
};

int main(int argc, char **argv)
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(6, new ListNode(1))));
    Solution s;
    auto result = s.addTwoNumbers(l1, l2);
    print_list_node(result);
}