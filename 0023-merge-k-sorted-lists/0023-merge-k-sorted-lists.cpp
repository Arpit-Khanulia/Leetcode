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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        vector<int>ans;
        
        for(auto i: lists){
            
            ListNode* temp = i;
            
            while(temp!= NULL){
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        sort(ans.begin(),ans.end());
        
        ListNode * head = new ListNode();
        ListNode * prev = head;
        for(int i: ans){
            
            ListNode * node = new ListNode(i);
            prev->next = node;
            prev = node;

        }
        
        
        return head->next;
    }
};