## Intuition
A binary tree is symmetric if its left and right subtrees are mirror images of each other. Their corresponding nodes must have equal values, and their child nodes must appear in opposite positions.

## Approach
1. Create an `isMirror()` function that compares the left and right subtrees recursively.
2. If both nodes are `NULL`, return `true`.
3. If only one node is `NULL`, return `false`.
4. Check whether both node values are equal.
5. Recursively compare the left child of the first tree with the right child of the second tree, and vice versa.
6. In `isSymmetric()`, handle an empty tree and call `isMirror()` on the root's left and right subtrees.

## Complexity
- **Time Complexity:** O(n), where `n` is the number of nodes in the tree.
- **Space Complexity:** O(h), where `h` is the height of the tree, due to the recursive call stack. In the worst case, this is O(n).

## Code
```cpp
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;

        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
```
