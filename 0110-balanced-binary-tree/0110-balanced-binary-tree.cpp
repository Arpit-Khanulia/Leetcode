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
    
    int check(TreeNode * root){
        
        if(root == NULL) return 1;
        
        int a = check(root->left);
        if(a == 0) return false;
        
        int b = check(root->right);
        if(b == 0) return false;
        
        if(abs(a-b) > 1) return false;
        
        return max(a,b)+1;

    }

    bool isBalanced(TreeNode* root) {
        
        return check(root);
        
    }
};