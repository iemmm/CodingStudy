/*
 *给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

注意: 合并过程必须从两个树的根节点开始。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-two-binary-trees
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
class Solution {
public:
    //   递归三部曲：
    //1. 确定递归函数的返回值和参数，这里返回值是合并后的二叉树的根节点指针，
    //参数是两个要合并的二叉树的根节点指针；
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //2. 确定终止条件
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
    //3. 确定单层递归逻辑
    //   单层递归逻辑就是遍历两个二叉树，三种遍历顺序都是可以的。
        root1->val += root2->val;//中
        root1->left = mergeTrees(root1->left, root2->left);//左
        root1->right = mergeTrees(root1->right, root2->right);//右//在解题过程中，把这行的等号左边的root1写成了root2导致运行出错，画了些时间找这个错误，
//分析原因是写代码时用了代码提示，但是选错了变量名，因此在写变量时尽量不用代码提示。尽量写代码不用代码提示。
        return root1;
    }
};
