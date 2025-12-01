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
    ListNode* swapNodes(ListNode* head, int k) {

        if(head == nullptr) return nullptr;
        if(head->next ==nullptr && k ==1) return head;
        ListNode* dum = new ListNode();
        dum->next = head;
        ListNode* fast =dum;
        ListNode* slow =dum;
        ListNode* temp = new ListNode();
        int count = 0;
        for(int i=0;i<k;i++){
            fast = fast->next;
            count++;
            if(count==k) temp = fast;
        }
        
        while(fast->next!=nullptr){
            fast= fast->next;
            slow= slow->next;
            count++;
            // if(count == k){
            //     temp = slow;
            // }
        }

        int s = temp->val;
        temp->val = slow->next->val;
        slow->next->val = s;

        return head;
        
    }
};