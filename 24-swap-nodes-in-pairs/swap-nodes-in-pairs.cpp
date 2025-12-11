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

    ListNode* swapPairs(ListNode* head) {
         if(head == nullptr|| head->next==nullptr ) return head;
        ListNode* temp= head;
        ListNode* rhead = head;
        ListNode* dum = new ListNode();
        ListNode* rend = dum;
        

        int count = 1;

        while(temp!=nullptr){
            if(count%2 ==0){
                
                ListNode* nll = temp->next;
                temp->next = nullptr;
                
                ListNode* newhead = reverse(rhead);
                if(count == 2) dum->next = newhead;
                rend->next= newhead;
                rend = rhead;
                rhead->next = nll;
                rhead = rhead->next; 
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