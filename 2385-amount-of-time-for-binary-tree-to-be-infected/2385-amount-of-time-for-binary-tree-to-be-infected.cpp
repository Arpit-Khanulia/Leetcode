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
    
    TreeNode* find(TreeNode * root, int target){
        
        if(root == NULL) return NULL;
        if(root->val == target) return root;
        
        TreeNode* a = NULL;
        TreeNode* b = NULL;
            
        a = find(root->left,target);
        b = find(root->right,target);
        
        if(a) return a;
        if(b) return b;
        return NULL;
        
    }
    int amountOfTime(TreeNode* root, int start) {
        
        map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        
        int minutes =-1;
        set<TreeNode*>visited;
        q.push(find(root,start));
        
        
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0; i<size;i++){
                TreeNode* temp = q.front();
                visited.insert(temp);
                q.pop();
                
                if(temp->left and visited.find(temp->left) == visited.end()) q.push(temp->left); 
                if(temp->right and visited.find(temp->right) == visited.end()) q.push(temp->right); 
                if(parent[temp] and visited.find(parent[temp]) == visited.end()) q.push(parent[temp]); 
                
            }
            minutes++;
        }
        
        return minutes;
        
    }
};