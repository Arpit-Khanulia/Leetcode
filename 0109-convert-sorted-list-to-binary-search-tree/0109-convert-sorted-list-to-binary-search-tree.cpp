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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    
    TreeNode * makenode(vector<int>&arr, int l, int r){
        
        if(l<=r) {
            
            TreeNode * temp = new TreeNode();
            int mid = (l+r)/2;
            temp->val = arr[mid] ;
            temp->left = makenode(arr,l,mid-1);
            temp->right = makenode(arr,mid+1,r);

            return temp;
            
        }
        
        return NULL;
        

    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int>arr;
        while(head != NULL){
            
            arr.push_back(head->val);
            head = head->next;
            
        }
        
        TreeNode* ans = makenode(arr,0,arr.size()-1);
        
        return ans;
        
    }
};