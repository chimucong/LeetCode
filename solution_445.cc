#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2){
        stack<int> s1, s2;
        while(l1 != nullptr){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode * result = nullptr;
        int carry = 0;
        while(!s1.empty() && !s2.empty()){
            int sum = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            carry = sum / 10;
            sum = sum % 10;
            ListNode * cur = new ListNode(sum, result);
            result = cur;
        }
        if(s1.empty()){
            s1 = std::move(s2);
        }
        while(!s1.empty()){ 
            int sum = carry + s1.top();
            s1.pop();
            carry = sum / 10;
            sum = sum % 10;
            ListNode * cur = new ListNode(sum, result);
            result = cur;
        }
        if(carry > 0){
            ListNode * cur = new ListNode(carry, result);
            result = cur;
        }
        return result;
    }
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode dummy;
        ListNode * p = & dummy;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            p->next = new ListNode(sum);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == nullptr){
            l1 = l2;
        }
        while(l1 != nullptr){
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            p->next = new ListNode(sum);
            p = p->next;
            l1 = l1->next;
        }
        if(carry > 0){
            p->next = new ListNode(carry);
        }
        return reverse(dummy.next);
    }


    ListNode * reverse(ListNode * l){
        ListNode * prev = nullptr;
        while(l != nullptr){
            ListNode * next = l->next;
            l->next = prev;
            prev = l;
            l = next;
        }
        return prev;
    }
};