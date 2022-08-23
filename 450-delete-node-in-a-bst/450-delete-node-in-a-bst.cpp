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
    
    TreeNode * editlink(TreeNode* root){
        
        if(root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        
        TreeNode * lastright = find(root->left);
        lastright->right = root->right;
        
        return root->left;
    }
    
    TreeNode * find(TreeNode * root){
        
        while(root->right != NULL)
            root = root->right;
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode* ans = root;
        
        if(root==NULL)
            return root;
        
        if(root->val == key)
            return editlink(root);
        
        while(root != NULL)
        {
            
            if(key< root->val){
                
                if(root->left && root->left->val == key){
                    
                    root->left = editlink(root->left);
                    break;
                }
                root = root->left;
                
            }
            else{
                
                if(root->right && root->right->val == key){
                    root->right = editlink(root->right);
                    break;
                }
                root = root->right;
                
            }
            
        }
        
        return ans;
        
    }
};