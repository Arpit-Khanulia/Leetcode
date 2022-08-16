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
    
    TreeNode* insert(TreeNode * root,int val, TreeNode * root2){
        
        
        if( root == NULL){
            return root2;
        }
        
        if(val < root->val)
        {
            if(root->left == NULL)
            {
                TreeNode * node = new TreeNode(val);
                root->left = node;
                return root2;
            }
            return insert(root->left,val,root2);
            
        }
            
        if(root->right == NULL)
        {
                TreeNode * node = new TreeNode(val);
                root->right = node;   
                return root2;
        }
        return insert(root->right,val,root2);
        
        
    }
    
    
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL)
        {
            TreeNode * node = new TreeNode(val);
            return node;
        }
        
        return insert(root,val,root);
        
        
    }
};