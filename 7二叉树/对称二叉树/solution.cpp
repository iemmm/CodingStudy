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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            TreeNode* left = que.front(); que.pop();
            TreeNode* right = que.front(); que.pop();
            if(!left && !right) {
                continue;
            }
            if(!left || !right || (left->val != right->val)){
                return false;
            }
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};

//递归法

class Solution {
public:
    bool compair(TreeNode* left, TreeNode* right){
            if(left == NULL && right != NULL) return false;
            if(left != NULL && right == NULL) return false;
            if(left == NULL && right == NULL) return true;
            if(left->val != right->val) return false;
            bool outside = compair(left->left, right->right);
            bool inside = compair(left->right, right->left);
            bool result = outside && inside;
            return result;
        }
    bool isSymmetric(TreeNode* root) {
        bool res = compair(root->left, root->right);
        return res;
    }
};

