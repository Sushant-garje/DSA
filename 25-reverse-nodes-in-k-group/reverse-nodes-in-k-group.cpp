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
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next ==nullptr) return head;

        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newhead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr ) return head;
        ListNode* temp= head;
        ListNode* rhead = head;
        ListNode* rend = new ListNode();
        ListNode* end = nullptr;
        ListNode* dum = new ListNode();
        

        int count = 1;

        while(temp!=nullptr){
            if(count%k ==0){
                
                ListNode* nll = temp->next;
                temp->next = nullptr;
                
                ListNode* newhead = reverse(rhead);
                if(count == k) dum->next = newhead;
                rend->next= newhead;
                rend = rhead;
                rhead->next = nll;
                rhead = rhead->next;
                end = temp;
                temp = nll;
                count++;
            }
            else
            {
                temp= temp->next;
                count++;
            }
            


        }

        return dum->next;
        
    }
};