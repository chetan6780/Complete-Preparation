# [572. Subtree of Another Tree](hhttps://leetcode.com/problems/subtree-of-another-tree/)

### Code

```cpp
class Solution {
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (subRoot == nullptr || root == nullptr)
            return false;
        if (root->val != subRoot->val)
            return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (check(root, subRoot))
            return true;
        if (root == nullptr)
            return false;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
```
