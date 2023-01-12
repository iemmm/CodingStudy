/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归法
class Solution {
public:
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int depth = 1 + max(left, right);
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getHeight(root);
    }
};

//迭代法
//
//
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root == NULL) return 0;
        que.push(root);
        int depth = 0;
        while(!que.empty()){
            depth++;
            int size = que.size();
            while(size--){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left != NULL) que.push(cur->left);
                if(cur->right != NULL) que.push(cur->right);
            }
        }
        return depth;
    }
};
