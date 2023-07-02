# [110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

### Recursive

-   if root is null, return true.
-   get height of left and right subtree.
-   if it differs by more than 1, return false.
-   check if left and right subtree are balanced.

### Code

```cpp
class Solution {
private:
    int getHeight(TreeNode* root)
    {
        if (root == NULL) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

public:
    bool isBalanced(TreeNode* root)
    {
        if (root == NULL) return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(left - right) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
```
