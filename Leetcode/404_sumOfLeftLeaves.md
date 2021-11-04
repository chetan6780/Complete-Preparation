# [404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/) 🌟

Given the root of a binary tree, return the sum of all left leaves.

### Simple recursive dfs

- We want sum of left leaf nodes only, so we can take additional boolean variable to specify whether it is left or not.
- we recursively go to left and right leaf node, if leaf node is left then we return its value else return 0.
- return dfs for left and right of tree.
- **Time Complexity:** O(n), we traverse the tree once
- **Space Complexity:** O(1) if we don't consider recursion stack, **O(height-of-tree)** if we do.

### Code

```cpp
class Solution{
    int dfs(TreeNode *root, bool isLeft){
        if (!root) return 0;
        if (root->left == NULL && root->right == NULL){
            if (isLeft)
                return root->val;
            else
                return 0;
        }
        return dfs(root->left, true) + dfs(root->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode *root){
        if (!root) return 0;
        return dfs(root, false);
    }
};
```
