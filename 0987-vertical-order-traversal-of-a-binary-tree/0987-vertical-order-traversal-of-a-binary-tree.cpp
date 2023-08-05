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
    
    void find(TreeNode * root, map<int,map<int,multiset<int>>>&ds ,int row,int col){
        
        if(root == NULL) return ;
        
        ds[col][row].insert(root->val);
        
        find(root->left,ds,row+1,col-1);
        find(root->right,ds,row+1,col+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        map<int,map<int,multiset<int>>>ds;
        find(root,ds,0,0);
        
        vector<vector<int>>ans;
        
        for(auto i: ds){
            
            vector<int>temp;
            
            for(auto j: i.second){
                
                for(auto k: j.second) temp.push_back(k);   
            }
            ans.push_back(temp);
        }
        
        
        return ans;
        
    }
};