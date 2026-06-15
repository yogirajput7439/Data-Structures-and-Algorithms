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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
// solutions

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            depth++;
        }

        return depth;
    }
};
