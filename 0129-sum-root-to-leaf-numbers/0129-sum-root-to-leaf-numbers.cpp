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
    
    void find (TreeNode * root, int &ans,string& ds){

        if(root == NULL) return ;

        ds+= to_string(root->val);
        
        if(root->left == NULL and root->right == NULL)
            ans  = ans + stoi(ds);
        
        find(root->left,ans,ds);
        find(root->right,ans,ds);
        ds.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        
        int ans =0;
        string ds="";
        find(root,ans,ds);
        return ans;
        
    }
};