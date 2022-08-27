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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int ub = INT_MAX;
        int i =0;
        return create(preorder,ub,i);

        
    }
    
    TreeNode * create(vector<int>&preorder, int ub,int &i){
        
        if(i == preorder.size() || preorder[i] > ub)
            return NULL ;

            
            TreeNode * node = new TreeNode(preorder[i]);
            i++;
            node->left = create(preorder,node->val,i);
            node->right = create(preorder,ub,i);
            
            return node;
        
        
    }
};