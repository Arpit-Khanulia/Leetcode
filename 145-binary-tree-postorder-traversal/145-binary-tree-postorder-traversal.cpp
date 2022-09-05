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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode *> s;
        s.push(root);
        
        vector<int>ans;
        if(root == NULL)
            return ans;
        vector<int>rev;
        
        while(!s.empty()){
            
            TreeNode * node = s.top();
            s.pop();
            
            rev.push_back(node->val);

            if(node->left)
            s.push(node->left);
            if(node->right)
            s.push(node->right);
            
        }
        
        for(int i= rev.size()-1;i>=0; i--)
            ans.push_back(rev[i]);
        
        return ans;
    }
};