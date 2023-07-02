# [543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

### Recursive O(N^2)

-   `Maximum diameter = max(diameter of left subtree, diameter of right subtree, height of left subtree + height of right subtree + 1)`

```cpp
class Solution {
private:
    int height(TreeNode* root)
    {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int diameter(TreeNode* root)
    {
        if (root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int leftDig = diameter(root->left);
        int rightDig = diameter(root->right);

        return max({1 + leftHeight + rightHeight, leftDig, rightDig});
    }

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == NULL) return 0;
        return diameter(root)-1;
    }
};
```

### Recursive O(N) Time ans space

```cpp
class Solution {
private:
    int height(TreeNode* root, int& ans)
    {
        if (root == NULL) return 0;

        int leftHeight = height(root->left, ans);
        int rightHeight = height(root->right, ans);

        ans = max(ans, leftHeight + rightHeight); // update answer

        return max(leftHeight, rightHeight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans = 0;
        height(root, ans);
        return ans;
    }
};
```
