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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        string ds;
        
        count(root,ds,ans);
        
        return ans;
        
    }
    
    void count(TreeNode * root,string ds,vector<string> & ans){
        
        if(root == NULL)
            return ;
        
        if(root->left == NULL && root->right == NULL){
            ds.append(to_string(root->val));
            ans.push_back(ds);
            return;
        }
        
        ds.append(to_string(root->val));
        ds.append("->");
        count(root->left,ds,ans);
        count(root->right,ds,ans);
        
    }
};