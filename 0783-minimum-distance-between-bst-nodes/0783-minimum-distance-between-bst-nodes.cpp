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
    
    void find(int &mini, TreeNode * root,int& prev){
        
        if(root == NULL) return ;
        
        find(mini,root->left,prev);
        
        if(prev != -1) mini = min(mini, root->val - prev);
        prev = root->val;
        
        find(mini,root->right,prev);
        
        
        
        
    }
    int minDiffInBST(TreeNode* root) {
        
        int mini = INT_MAX;
        int a= -1;
        find(mini,root,a);
        return mini;
    }
};