/*
 *给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-binary-tree
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
    //[left,right)区间，这里规定使用左闭右开区间，主要是因为要利用size()作为边界；
    TreeNode* traversal(vector<int>& nums, int left, int right){
        if(left >= right) return nullptr;
        int maxindex = left;
        for(int i = left; i < right; i++){
            if(nums[i] > nums[maxindex]) maxindex = i;
        }
        TreeNode* root = new TreeNode(nums[maxindex]);
        //[left,maxindex)
        root->left = traversal(nums, left, maxindex);
        //[maxindex + 1, end)
        root->right = traversal(nums, maxindex + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0 , nums.size());
    }
};
