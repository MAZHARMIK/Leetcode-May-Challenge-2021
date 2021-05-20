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
            temp = {};
            
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                
                temp.push_back(curr->val);
                
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
            result.push_back(temp);
        }
        
        return result;
    }
};
