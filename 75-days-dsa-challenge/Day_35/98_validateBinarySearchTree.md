# [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

### O(N) Time and O(N) space

-   Inorder traversal of the binary tree gives sorted array.
-   we can traverse the tree inorder and check if the array is sorted or not.

### O(N) Time solution

-   we will check if value is less than maximum and greater than minimum

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
