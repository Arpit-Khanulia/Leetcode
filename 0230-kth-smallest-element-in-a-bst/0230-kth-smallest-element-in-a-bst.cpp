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
    
    int find(TreeNode * root, int k, int &count){
        
        if(root == NULL) return 0;
        
        int a = find(root->left,k,count);
        if(a) return a;
        count++;
        
        if(count == k) return root->val;
        
        int b = find(root->right,k,count);
        if(b) return b;
        
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int count =0;
        return find(root,k,count);
    }
};