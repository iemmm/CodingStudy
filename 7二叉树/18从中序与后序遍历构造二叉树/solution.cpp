/*给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。



来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
  */
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
    //确定参数和返回值
    TreeNode* traversal(vector<int> & inorder, vector<int>& postorder){
        //递归结束条件
        if(postorder.size() == 0) return nullptr;
        int inval = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(inval);
        if(postorder.size() == 1) return root;
        int index;
        for(index = 0; index < inorder.size(); index++){
            if(inorder[index] == inval) break;
        }
        //切割中序数组
        //[0,index)
        vector<int> inorderleft(inorder.begin(), inorder.begin() + index );
        //[index + 1, end)
        vector<int> inorderright(inorder.begin() + index + 1, inorder.end());
        //切割后续数组
        //[0,index)
        vector<int> postorderleft(postorder.begin(), postorder.begin() + index);
        //[index,end - 1)
        vector<int> postorderright(postorder.begin() + index, postorder.end() - 1);
        root->left = traversal(inorderleft, postorderleft);
        root->right = traversal(inorderright, postorderright);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};
