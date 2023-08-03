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
    
    int height(TreeNode * root){
        if(root == NULL) return 0;
        
        int lefth = height(root->left);
        int righth = height(root->right);
        
        if(lefth == -1 or righth  == -1) return -1;
       
        if(abs(lefth - righth) > 1) return -1;
        
        return max(lefth,righth) +1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) return 1;
        
        int check = height(root);
        
        return check == -1?  0 : 1;
        
    }
};