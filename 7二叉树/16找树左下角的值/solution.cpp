/*
 *给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

 * */
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

 //递归法
class Solution {
public:
    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode* root, int depth){
        if(!root->left && !root->right){
            if(depth > maxDepth){
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if(root->left){
            depth++;
            traversal(root->left, depth);
            depth--;
        }
        if(root->right){
            depth++;
            traversal(root->right, depth);
            depth--;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
       traversal(root, 0);
       return result;
    }
};

//迭代法

//层序遍历
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<int> result;
        while (!que.empty()) {
            int size = que.size();
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                result.push_back(node->val);
                if (node->right) que.push(node->right);
                if (node->left) que.push(node->left);
            }
            
        }
        int i = result.size();
        return result[i - 1];
    }
};

