# LeetCode 100 — Same Tree

## Intuition

Two binary trees are considered the same if:

1. They have the same structure.
2. The corresponding nodes have the same values.

We can recursively compare both trees at the same time.

For every pair of nodes:

* If both are `nullptr`, they are equal.
* If one is `nullptr` and the other is not, the trees are different.
* If their values are different, the trees are different.
* Otherwise, compare their left subtrees and right subtrees.

Both subtrees must be identical for the complete trees to be the same.

## Approach

Use recursion to compare the two trees.

For each pair of corresponding nodes:

1. Check if both nodes are `nullptr`.
2. Check if only one node is `nullptr`.
3. Check whether their values are equal.
4. Recursively compare:

   * Left subtree
   * Right subtree
5. Return `true` only if both subtrees are identical.

## Example

Tree 1:

```text
    1
   / \
  2   3
```

Tree 2:

```text
    1
   / \
  2   3
```

Both trees have:

* Same structure
* Same node values

Therefore:

```text
true
```

### Another Example

Tree 1:

```text
    1
   /
  2
```

Tree 2:

```text
    1
     \
      2
```

The values are the same, but the structure is different.

Therefore:

```text
false
```

## Complexity

### Time Complexity

```text
O(n)
```

Each node is visited once.

### Space Complexity

```text
O(h)
```

where `h` is the height of the tree because of the recursive call stack.

For a balanced tree:

```text
O(log n)
```

For a completely skewed tree:

```text
O(n)
```

## C++ Solution

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
```

## Key Idea

The most important concept is:

```text
Same value + Same left subtree + Same right subtree
= Same Tree
```

The recursion compares corresponding nodes of both trees simultaneously.

## Pattern

**Binary Tree + Recursion + DFS**

This is a fundamental binary tree recursion problem and helps build the foundation for more advanced tree problems.
