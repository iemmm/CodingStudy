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

给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-complete-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
 //迭代法
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if(root == NULL) return 0;
        que.push(root);
        int num = 0;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                TreeNode* cur = que.front();
                que.pop();
                num++;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return num;
    }
};

//递归法
class Solution {
public:
    int getNum(TreeNode* root){
        if(root == NULL) return 0;
        int left = getNum(root->left);
        int right = getNum(root->right);
        return left + right + 1;
    }
    int countNodes(TreeNode* root) {
        int res = getNum(root);
        return res;
    }
};
