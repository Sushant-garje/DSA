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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr ) return head;
        if(head->next == nullptr) return nullptr;



        ListNode* dum = new ListNode();
        dum->next = head;
        ListNode* fast = head;
        ListNode* slow = dum;

        while(fast != nullptr &&fast->next != nullptr){
            fast = fast ->next->next;
            slow = slow->next;

        }
        slow->next = slow->next->next;
        return head;
        
    }
};