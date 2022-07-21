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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        map<int,map<int,multiset<int>>>ds;
        traverse(root,0,0,ds);
        
        vector<vector<int>>ans;
        
        for(auto &i: ds){
            vector<int> temp;
            for(auto &j : i.second)
            {
                
                for(auto &k : j.second)
                temp.push_back(k);
                
                
            }
            
            ans.push_back(temp);

        }
        
        return ans;
    }
    
    void traverse(TreeNode * root,int horizontal,int vertical,map<int,map<int,multiset<int>>>&ds){
        
        
        if(root == NULL)
            return;
        
        ds[horizontal][vertical].insert(root->val);
        traverse(root->left,horizontal -1,vertical +1,ds);
        traverse(root->right,horizontal +1,vertical +1,ds);
        
        
    }
};