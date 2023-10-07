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
    
void reverse(ListNode *start, ListNode *end){
        
        if(start == end) return;
        
        ListNode* prev = NULL;
        ListNode* curr = start;
        ListNode* n = start->next;
        
        while(prev!= end){
            
            curr->next = prev;
            prev = curr;
            curr = n;
            
            if(n->next != NULL) n = n->next;
        }
        
    }
    
    ListNode* solve(ListNode * head, int k){
        
        if(head == NULL) return head;
        ListNode* start = head;
        ListNode* end = head;
        
        int i = k-1;
        while(i--){
        
            end = end->next;
            if(!end) return head;
            
        }
        
        ListNode * rightside = solve(end->next,k);
        
        reverse(start,end);
        
        start->next = rightside;
        
        return end;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL) return head;
        return solve(head,k);
    }
};