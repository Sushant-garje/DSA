/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2){
            // if(temp1==temp2) return temp1;
            if(temp1->next == nullptr && temp2->next == nullptr) return nullptr;
            if(temp1->next ==nullptr){
                temp1 = headB;
                temp2 = temp2->next;
                continue;

            }
            else if(temp2->next == nullptr){
                temp2 = headA;
                temp1 = temp1->next;
                continue;
            }
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            
        }

        return temp1;
        
    }
};