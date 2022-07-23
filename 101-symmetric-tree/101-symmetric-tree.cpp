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
    bool isSymmetric(TreeNode* root) {
        
        
        return check(root->left,root->right);
    }
    
    bool check(TreeNode * head1,TreeNode * head2){
        
        if(head1 == NULL && head2 == NULL)
            return 1;
        
        if(head1 && !head2)
            return 0;
        
        if(head2 && !head1)
            return 0;
        
        if(head1->val  == head2->val)
            return check(head1->left,head2->right) && check(head1->right,head2->left);
        
        return 0;
        

    }
};