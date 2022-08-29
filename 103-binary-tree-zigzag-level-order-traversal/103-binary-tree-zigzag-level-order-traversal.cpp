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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        

        
    bool flag = true;
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> ans;
        
    if(root == NULL)
        return ans;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            int index = (flag) ? i : (size - 1 - i);
            row[index] = temp->val;
        }

        flag = !flag;
        ans.push_back(row);
    }
        
        return ans;
        
    }
};