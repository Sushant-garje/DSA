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
    ListNode *st(ListNode* node,ListNode* head){
        ListNode* temp = head;
        while(temp!=node){
            node = node->next;
            temp = temp ->next;
        }
        return temp;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr ) return nullptr;
        ListNode* pt1 = head;
        ListNode* pt2 =head;

        while(pt2!=nullptr && pt2->next != nullptr){
            pt1 = pt1->next;
            ListNode* ans = pt2->next;
            pt2= pt2->next->next;
            if(pt1 == pt2) return st(pt1,head);
        }

        return nullptr;

    }
};