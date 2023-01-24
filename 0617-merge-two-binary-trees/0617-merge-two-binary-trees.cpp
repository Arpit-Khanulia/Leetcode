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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode * root3 = NULL;
        
        
        if (root1 == NULL && root2 == NULL)
            return NULL;
        
        if(root1 != NULL && root2!= NULL)
        {
            int val1 = root1->val;
            int val2 = root2->val;
            root3 = new TreeNode(val1 + val2); 
            root3->left = mergeTrees(root1->left,root2->left);
            root3->right = mergeTrees(root1->right,root2->right);
            
        }

        
        else if (root1 != NULL && root2 == NULL)
        {    
            int val1 = root1->val;
            int val2 = 0;
            root3 = new TreeNode(val1 + val2); 
            root3->left = mergeTrees(root1->left,NULL);
            root3->right = mergeTrees(root1->right,NULL);
        }    
        
        else if (root1 == NULL && root2 != NULL)
        {
            int val1 = 0;
            int val2 = root2->val;
            root3 = new TreeNode(val1 + val2); 
            root3->left = mergeTrees(NULL,root2->left);
            root3->right = mergeTrees(NULL,root2->right);
        }   
        
        return root3;
        
        
        
    }
};