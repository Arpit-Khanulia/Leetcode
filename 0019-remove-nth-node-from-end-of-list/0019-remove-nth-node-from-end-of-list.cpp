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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next == NULL)
            return NULL;
        
        ListNode* temp = head;
        int count =0;
        
        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        
        int no = count -n;
        temp = head;
        
        if(no==0)
            return head->next;
        
        while(--no)
            temp = temp->next;
        
        temp->next = temp->next->next;
        
        return head;
    }
};