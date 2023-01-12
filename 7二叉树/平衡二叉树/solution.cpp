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
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

*/
class Solution {
public:
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        int left = getHeight(root->left);
        if(left == -1) return -1;
        int right = getHeight(root->right);
        if(right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
      return getHeight(root) == -1 ? false : true;
    }
};
