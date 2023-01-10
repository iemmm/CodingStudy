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
        queue<TreeNode*> qu;
        vector<vector<int>> result;
        if(root == NULL) return result;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> res;
            while(size--){
                TreeNode* cur = qu.front();
                qu.pop();
                res.push_back(cur->val);
                if(cur->left != NULL) qu.push(cur->left);
                if(cur->right != NULL) qu.push(cur->right);
            }
            result.push_back(res);
        }
        return result;
    }
};
