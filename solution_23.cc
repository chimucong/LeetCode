#include <queue>

using namespace std;
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *lhs, ListNode *rhs) {
            return lhs->val < rhs->val;
        };
        priority_queue<ListNode * /**, vector<ListNode *>, decltype(cmp) **/> q(cmp);
        for (auto node : lists)
        {
            q.push(node);
        }
        ListNode dummy;
        ListNode *p = &dummy;
        while (!q.empty())
        {
            ListNode *current = q.top();
            q.pop();
            p->next = current;
            p = current;
            if (current->next != nullptr)
            {
                q.push(current->next);
            }
        }
        return dummy.next;
    }
};

int main()
{
    return 0;
}