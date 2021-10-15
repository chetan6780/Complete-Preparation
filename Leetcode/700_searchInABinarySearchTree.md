# [700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/) 🌟

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

### O(N) Time, Recursive solution

- if root is null return null.
- if root's value == val return the root.
- if required value is less than root's value, recurse on left subtree.
- else recurse on right subtree.

### Code

```cpp
class Solution{
public:
    TreeNode *searchBST(TreeNode *root, int val){
        if (root == NULL) return NULL;
        if (root->val == val) return root;

        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
```

### O(N) Time, Iterative solution

- Same as recursion.

### Code

```cpp
class Solution{
public:
    TreeNode *searchBST(TreeNode *root, int val){
        if (root == NULL) return NULL;

        while (root != NULL){
            if (root->val == val) return root;
            else if (val < root->val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};
```
