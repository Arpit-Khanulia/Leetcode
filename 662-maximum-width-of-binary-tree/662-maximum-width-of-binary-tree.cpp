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
        
        queue<pair<TreeNode * ,int>>q;
        
        q.push({root,0});
        int maxi =0;
        
        while(!q.empty()){
            
            int mini = q.front().second;
            int size = q.size();
            int first=0;
            int last=0;
            
            for(int i =0;i<size;i++){
                
                auto temp = q.front();
                q.pop();
                TreeNode * node = temp.first;
                long long  cur = temp.second - mini;
                    
                if(i == 0)
                    first = temp.second;
                if(i == size-1)
                    last = temp.second;
            
                
                if(node->left)
                    q.push({node->left,2*cur + 1});
                
                if(node->right)
                    q.push({node->right,2*cur +2 });
     
            }
            int width = abs(last - first) +1;
            if(width >maxi)
                maxi = width;
            width = 0;
        }
        
        return maxi;
 
        
    }
};