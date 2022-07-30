/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
        vector<int>ans;
        map<TreeNode * , TreeNode *>m;
        markparent(root,m);
        
        queue<TreeNode*>q;
        q.push(target);
        
        set<TreeNode*> visited;
        visited.insert(target);
        
        for(int i =0;i<k;i++){
            
            int size = q.size();
            for(int i =0;i<size;i++){
                
                TreeNode * temp = q.front();
                q.pop();
                
                if(temp->left && !visited.count(temp->left)){
                    q.push(temp->left);
                    visited.insert(temp->left);
                }
                
                if(temp->right&& !visited.count(temp->right)){
                    q.push(temp->right);
                    visited.insert(temp->right);
                }
                
                if(m[temp] && !visited.count(m[temp])){
                    q.push(m[temp]);
                    visited.insert(m[temp]);
                }
            }
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
            
        
        return ans;
        
        
    }
    
    void markparent(TreeNode * root,map<TreeNode *,TreeNode*>&m){
        
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            
            for(int i =0;i<size;i++)
            {
                TreeNode * temp = q.front();
                q.pop();
                
                if(temp->left)
                {
                    q.push(temp->left);
                    m[temp->left] = temp;
                    
                }
                    
                if(temp->right)
                {
                    q.push(temp->right);
                    m[temp->right] = temp;
                }  
                
            }
        }
        
        
            
    }
    
    
    
    
};