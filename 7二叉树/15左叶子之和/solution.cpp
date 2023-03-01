/*
 *给定二叉树的根节点 root ，返回所有左叶子之和。
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

 //迭代法 中左右
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == nullptr)  return 0;
        st.push(root);
        int result;
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->left && !node->left->left && !node->left->right){
                result += node->left->val;
            }
            if(node->right) st.push(node->right);//右
            if(node->left) st.push(node->left);//左
        }
        return result;
    }
};
