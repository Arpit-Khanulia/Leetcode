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
        
        ListNode * ans  = new ListNode();
        ListNode * head = ans;
        

        
        while(list1 != NULL && list2 != NULL){
            
            ListNode * temp = new ListNode;
            if(list1->val < list2->val)
            {
                temp->val = list1->val;
                list1 = list1->next;
                
            }
                
            else{
                temp->val = list2->val;
                list2 = list2->next;
                
            } 
                
            
            ans->next  = temp;
            ans = temp;     
        }
        
        while(list1){
            ListNode * temp = new ListNode(list1->val);
            ans->next = temp;
            ans = temp;
            list1 = list1->next;
        }
        
        while(list2){
            ListNode * temp = new ListNode(list2->val);
            ans->next = temp;
            ans = temp;
            list2 = list2->next;
        }
        
        return head->next;
        
    }
};