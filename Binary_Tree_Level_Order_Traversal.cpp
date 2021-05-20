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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        
        queue<TreeNode*> que;
        que.push(root);
        vector<int> temp;
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                
                temp.push_back(curr->val);
                
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
            result.push_back(move(temp));
        }
        
        return result;
    }
};
