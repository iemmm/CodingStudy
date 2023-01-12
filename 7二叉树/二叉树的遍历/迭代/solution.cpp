//前序遍历

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->right != NULL) st.push(cur->right);
            if(cur->left != NULL) st.push(cur->left);
        }
        return result;
    }
};


//中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if(root == NULL) return result;
        while(root != NULL || !st.empty()){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};

//后序遍历可以通过修改中序遍历顺序，然后翻转遍历结果得到

