/*
 *给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。
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
    void travesal(TreeNode* node, vector<int>&path, vector<string>&result){
        //中
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL){
            string paths;
            for(int i = 0; i < path.size() - 1; i++){
                paths += to_string(path[i]);
                paths += "->";
            }
            paths += to_string(path[path.size()-1]);
            result.push_back(paths);
            return;
        }
        //左
        if(node->left != NULL){
            travesal(node->left, path, result);
            path.pop_back();
        }
        //右
        if(node->right != NULL){
            travesal(node->right, path, result);
            path.pop_back();
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        travesal(root, path, result);
        return result;
    }
};
