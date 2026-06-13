// beast Solution.  //

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr)
            return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

// Optimal Solutions ----------------- //

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            result.push_back(curr->val);
            curr = curr->right;
        }

        return result;
    }
};
