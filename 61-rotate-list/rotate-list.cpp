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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==nullptr) return head;
        int count = 1;
        ListNode* temp = head;
        while(temp->next){
            count++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%count;
        k = count-k;
        while(k!=0){
            temp = temp->next;
            k--;
        }

        ListNode* newhead = temp->next;
        temp->next = nullptr;
        return newhead;
        
    }
};