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
        
        ListNode * a = headA;
        ListNode * b = headB;
        
        while(headA!= NULL || headB!= NULL){
            
            if(headA == headB) return headA;
            if(headA == NULL) headA = b; else headA = headA->next;
            if(headB == NULL) headB = a; else headB = headB->next;
            
        }
        
        return NULL;
    }
};