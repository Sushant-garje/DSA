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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return NULL;
        
        ListNode* pt1 = head;
        ListNode* pt2 = head;
        while(pt2 != nullptr && pt2->next != nullptr){
            pt1 = pt1->next;
            pt2 = pt2->next->next;

        }

        return pt1;
    }
};