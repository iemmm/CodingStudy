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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            while(size--){
                TreeNode* cur = que.front();
                que.pop();
                swap(cur->left, cur->right);
                if(cur->left != NULL) que.push(cur->left);
                if(cur->right != NULL) que.push(cur->right);
            }
        }
        return root;
    }
};
