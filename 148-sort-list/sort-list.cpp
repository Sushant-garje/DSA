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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        if(!list1 && list2) return list2;
        if(list1 && !list2) return list1;


        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* temp = new ListNode(-1);
        ListNode* dum = temp;

        while(t1 && t2){
            if(t1->val<=t2->val){
                temp->next = t1;
                temp = temp->next;
                t1= t1->next;
            }
            else{
                temp->next = t2;
                temp = temp->next;
                t2 = t2->next;
            }
        }
        while(t1){
            temp->next = t1;
            temp = temp->next;
            t1= t1->next;
        }
        while(t2){
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }


        return dum->next;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow= slow->next;
        }

        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* middle = findMiddle(head);
        ListNode* lhead = head;
        ListNode* rhead = middle->next;
        middle->next = nullptr;
        lhead = sortList(lhead);
        rhead = sortList(rhead);
        return mergeTwoLists(lhead,rhead); 
    }
};