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


ListNode * reverse(ListNode* head){
    
    if(head == NULL) return head;
    
    ListNode* prev = NULL;
    ListNode* cur =head;
    ListNode* n = head->next;
    
    while(cur!= NULL){
        
        cur->next = prev;
        prev = cur;
        cur = n;
        
        if(n) n = n->next;
    }
    
    return prev;
    
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        
        ListNode * hare = head;
        ListNode * tortoise = head;
        
        while(hare->next != NULL and hare->next->next != NULL){
            
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        
        
        ListNode* head2 = reverse(tortoise->next);
        tortoise->next =NULL;
        
        while(head and head2){
            
            if(head->val != head2->val) return false;
            
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
        
        
        
    }
};