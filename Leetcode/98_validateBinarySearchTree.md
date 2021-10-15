# [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) 🌟🌟

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

### O(N) Time and O(N) space

- Inorder traversal of the binary tree gives sorted array.
- we can traverse the tree inorder and check if the array is sorted or not.

### O(N) Time solution

- we will check if value is less than maximum and greater than minimum
- Refer [This](https://www.youtube.com/watch?v=s6ATEkipzow) , if you are not able to understand.

### Code

```cpp
class Solution{
private:
    bool valid(TreeNode *node, long long left, long long right){
        if (!node) return true;
        if (!(node->val < right && node->val > left)) return false;

        return (valid(node->left, left, node->val) &&
                (valid(node->right, node->val, right)));
    }

public:
    bool isValidBST(TreeNode *root){
        return valid(root, LONG_MIN, LONG_MAX);
    }
};
```
