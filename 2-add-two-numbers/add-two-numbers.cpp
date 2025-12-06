/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        int carry = 0;
        while(t1 || t2){
            int res = 0+carry;
            if(t1) res = res+t1->val;
            if(t2) res = res+t2->val;

            ListNode* anss = new ListNode(res%10);
            carry = res/10;
            ans->next = anss;
            ans = ans->next;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(carry){
            ListNode* anss = new ListNode(carry);
            ans->next = anss;
        }
        return temp->next;

        
    }
};