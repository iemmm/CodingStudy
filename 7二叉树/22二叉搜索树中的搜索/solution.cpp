/*
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/search-in-a-binary-search-tree
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
/*
    搜索二叉树:
    1.节点的左子树只包含小于当前节点的数
    2.节点的右子树只包含大于当前节点的数
    3.所有左子树和右子树都必须是搜索二叉树
*/

class Solution {
public:
    //1. 确定递归返回值和参数
    TreeNode* searchBST(TreeNode* root, int val) {
    //2. 确定结束条件
        if(root == NULL || root->val == val) return root;
    //3. 确定单层递归的逻辑
        TreeNode* result = NULL;
        if(root->val > val) result = searchBST(root->left, val);
        if(root->val < val) result = searchBST(root->right, val);
        return result;
    }
};
