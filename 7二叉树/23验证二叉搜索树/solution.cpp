/*
 *给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/validate-binary-search-tree
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

 //搜索二叉树的中序遍历是递增的
 //所以中序遍历将搜索二叉树，将节点的值放入数组中，检验数组是否递增。
class Solution {
private:
    vector<int> vec;
    void travel(TreeNode* root){
        if(root == NULL) return;
        travel(root->left);//左
        vec.push_back(root->val);//中
        travel(root->right);//右
    }
public:
    bool isValidBST(TreeNode* root) {
        vec.clear();
        travel(root);
        for(auto i = vec.begin(); i != vec.end(); i++){
            cout << *i <<",";
        }
        cout << endl;
        for(int i = 1; i < vec.size(); i++){
            if(vec[i-1] >= vec[i]) return false;
        }
        //*****第一次写这个for循环的时候没有把握好边界，从0开始，并出现了i+1;下次注意
        return true;
    }
};
