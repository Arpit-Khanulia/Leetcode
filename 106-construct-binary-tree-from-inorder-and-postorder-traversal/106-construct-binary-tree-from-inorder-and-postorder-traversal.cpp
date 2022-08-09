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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int> m ;
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] =i;
        
        return create(inorder,0,inorder.size()-1, postorder,0,postorder.size()-1,m);
        
    }
    
    TreeNode* create(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,map<int,int>&m){
        
        
        if(instart>inend || poststart> postend)
            return NULL;
        
        TreeNode* node = new TreeNode(postorder[postend]);
        
        int num = m[node->val];
        int num2 = num - instart ;
        
        
        node->left = create(inorder,instart,num-1,postorder,poststart,poststart + num2-1,m);
        node->right= create(inorder,num+1,inend,postorder,poststart + num2 ,postend-1,m);
        
        return node;
        
    }
};