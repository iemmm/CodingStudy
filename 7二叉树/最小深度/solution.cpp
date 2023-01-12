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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root == NULL) return 0;
        que.push(root);
        int depth = 0;
        while(!empty(que)){
            int size = que.size();
            depth++;
            while(size--){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left == NULL && cur->right == NULL) return depth;
                if(cur->left != NULL) que.push(cur->left);
                if(cur->right != NULL)que.push(cur->right);
            }
        }
        return depth;
    }
};

//递归法
//
class Solution {
public:
    int getMin(TreeNode* root){
        if(root == NULL) return 0;
        int left = 1 + getMin(root->left);
        int right = 1 + getMin(root->right);
        if(left>1&&right >1) return min(left, right);
        else if(left == 1) return right;
        return left;
    }
    int minDepth(TreeNode* root) {
        return getMin(root);
    }
};
