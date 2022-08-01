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
    int countNodes(TreeNode* root) {
        
       return count(root);
        
    }
    
    int count(TreeNode * root){
        if(root == NULL)
            return 0 ;
        
        int lh = lheight(root->left,1);
        int rh = rheight(root->right,1);
        
        // cout<<"root = "<<root->val<<" left = "<<lh<<" right = "<<rh<<endl;
        
        if(lh == rh)
            return pow(2,lh) -1;
        else return 1 + count(root->left) + count(root->right);
            
    }
    
    int lheight(TreeNode * root,int h){
        
        if(root == NULL)
            return h;
        
        return lheight(root->left,h+1);
        
        
    }
    
    int rheight(TreeNode * root,int h){
        
        if(root == NULL)
            return h;
        
        return rheight(root->right,h+1);
        
        
    }
};