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
    
    int find(TreeNode* root,int &maxi){
        
        if(root == NULL) return 0;
        
        int left = find(root->left,maxi);
        int right = find(root->right,maxi);
        
        int d = left + right;
        
        maxi = max(maxi,d);
        return max(left,right) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return NULL;
        int maxi = INT_MIN;
        
        find(root,maxi);
        return maxi;
    }
};