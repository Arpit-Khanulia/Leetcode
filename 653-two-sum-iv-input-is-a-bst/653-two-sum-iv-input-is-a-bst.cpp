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
    stack<TreeNode *>stackleft;
    stack<TreeNode *>stackright;
    
    void pushleft(TreeNode * root){
        
        while(root != NULL)
        {
            stackleft.push(root);
            root = root->left;
        }
    }
    
    void pushright(TreeNode * root){
        
        while(root != NULL){
            
            stackright.push(root);
            root = root->right;
        }
    }
    
    int getleft(TreeNode * root){
        
        TreeNode * temp = stackleft.top();
        stackleft.pop();
        if(temp->right)
            pushleft(temp->right);
        return temp->val;
        
    }
    
    int getright(TreeNode * root){
        TreeNode * temp = stackright.top();
        stackright.pop();
        if(temp->left)
            pushright(temp->left);
        return temp->val;
    }
    bool findTarget(TreeNode* root, int k) {
        
        pushleft(root);
        pushright(root);

        int l = getleft(root);
        int r = getright(root);

        
        while(l != r){

            if(k == l + r)
                return 1;
            
            if(k < (l + r))
                r = getright(root);
                
            else if(k > (l+r))
                l = getleft(root); 
            
        }
        
        return 0;
        
    }
};