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
        
        ListNode * hare =head;
        ListNode * tortoise = head;
        
        while(hare!= NULL &&  hare->next != NULL)
        {
            
            if(hare->next)
            hare = hare->next->next;
            
            if(tortoise->next)
            tortoise = tortoise->next;
        }
        
        return tortoise;
        
    }
};