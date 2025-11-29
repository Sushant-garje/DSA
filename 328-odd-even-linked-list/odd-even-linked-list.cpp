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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* oddptr = head;
        ListNode* evenptr = head->next;
        ListNode* change = evenptr;

        while(oddptr != nullptr && oddptr->next != nullptr && 
       evenptr != nullptr && evenptr->next != nullptr){
            oddptr->next = evenptr->next;
            oddptr = evenptr->next;
            evenptr->next = oddptr->next;
            evenptr = oddptr->next;
        }

        oddptr->next = change;

        return head;


        
    }
};