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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        if (root == NULL)
            return inorder;

        while (root != NULL) {

            if (root->left == NULL)
            {
                inorder.push_back(root->val);
                root = root->right;
            }

            else
            {

                TreeNode *prev = root->left;

                while (prev->right && prev->right != root)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = root;
                    inorder.push_back(root->val);
                    root = root->left;
                }

                else if (prev->right != NULL)
                {
                    prev->right = NULL;
                    root = root->right;
                    
                }
            }
            
        }

        return inorder;
        
    }
};