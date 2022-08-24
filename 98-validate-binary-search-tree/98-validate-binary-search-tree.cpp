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
    bool isValidBST(TreeNode* root) {
        
        
        long int left = LONG_MIN;
        long int right = LONG_MAX;
        
        return validate(root,left,right);
        
    }
    
    int validate(TreeNode * root,long int left, long int right){
        
        if(root == NULL)
            return 1;
        
        if(root->val < right && root->val > left)
            return validate(root->left,left,root->val) && validate(root->right,root->val,right);
            
        else return 0;
        
    }
};