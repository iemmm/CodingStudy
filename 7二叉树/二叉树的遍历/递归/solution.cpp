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

/**
 *中序遍历
 * */
class Solution {
public:
    void Traversal(TreeNode* cur, vector<int>& res){
        if(cur == nullptr) return;
        Traversal(cur->left, res);//左
        res.push_back(cur->val);//中
        Traversal(cur->right, res);//右
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Traversal(root, res);
        return res;
    }
};

/**
 *前序遍历
 * */
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& res){
        if(cur == nullptr) return;
        res.push_back(cur->val);//中
        traversal(cur->left, res);//左
        traversal(cur->right, res);//右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

/**
 *后序遍历
 * */
class Solution {
public:
    void Traversal(TreeNode* cur, vector<int>& res){
        if(cur == nullptr) return;
        Traversal(cur->left, res);//左
        Traversal(cur->right, res);//右
        res.push_back(cur->val);//中
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        Traversal(root, res);
        return res;
    }
};
