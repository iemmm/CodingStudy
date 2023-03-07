/*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

叶子节点 是指没有子节点的节点

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

 //迭代法
class Solution {
public:
//1. 确定递归参数何返回值
    bool traversal(TreeNode* root, int count){
        //2. 确定终止条件
        if(!root->left && !root->right && count == 0) return true;
        if(!root->left && !root->right) return false;
        //3. 确定单层递归逻辑
        if(root->left){
            count -= root->left->val;
            if(traversal(root->left, count)) return true;
            count += root->left->val;
        }
        if(root->right){
            count -= root->right->val;
            if(traversal(root->right,count)) return true;
            count += root->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        return traversal(root, targetSum - root->val);
    }
};
