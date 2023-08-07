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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        long long maxi =0;
        while(!q.empty()){
            
            long long mini = q.front().second;
            int size = q.size();
            long long  first =0;
            long long last =0;
            
            for(int i=0 ;i<size;i++){
                
                TreeNode * temp = q.front().first;
                long long index = q.front().second - mini;
                
                q.pop();
                
                if(i ==0) first = index;
                if(i == size-1) last = index;
                
                if(temp->left) q.push({temp->left,2*index +1});
                if(temp->right) q.push({temp->right,2*index + 2});
            }
            
            maxi = max(maxi,last - first +1);
        }
        
        return maxi;
    }
};
