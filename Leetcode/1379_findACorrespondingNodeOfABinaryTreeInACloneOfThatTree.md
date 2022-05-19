# [1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/) 🌟🌟

### DFS

-   Simple dfs traversal.
-   check if original node is null if yes then return null.
-   if original node is equal to target node then return the cloned node.
-   else recur ot left and right of the original and cloned subtrees and store the result in the left and right.
-   if left is not null return left else return right.

### Code

```cpp
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if (original == NULL)
            return NULL;
        if (original == target)
            return cloned;
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        TreeNode* right = getTargetCopy(original->right, cloned->right, target);
        return left != NULL ? left : right;
    }
};
```
