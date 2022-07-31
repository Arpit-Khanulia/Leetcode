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
    
    int find (TreeNode * root, int targetSum,int sum)
    {
        if(root == NULL)
            return NULL;
        sum = sum + root->val;
        if(sum == targetSum && root->left ==NULL && root->right == NULL)
            return 1;
       return find(root->left,targetSum,sum) || find(root->right,targetSum,sum);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum =0;
        
      return find(root,targetSum,sum);

        
        
        
    }
};