# [Diameter of the binary tree](https://leetcode.com/problems/diameter-of-binary-tree/)

-   [code studio](https://www.codingninjas.com/codestudio/problems/920552?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website)

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

### Brute force

-   As in the description the diameter of a binary tree is the length of the longest path between any two nodes in a tree.
-   **This path may or may not pass through the root**
-   So we can find the height of the left subtree and right subtree and add them to get the diameter of the tree.
-   Similarly calculate the diameter of the left subtree and right subtree.
-   return the maximum of the three(current diameter, left diameter, right diameter)
-   **Time complexity: O(N^2)**, as every time we are calculating the height of the tree.
-   **Space complexity: O(N)**

### Code

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

        return max(1 + leftHeight + rightHeight, max(leftDig, rightDig));
    }

public:

    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == NULL) return 0;
        // O(N^2)
        return diameter(root)-1;
    }
};
```

### Optimized

-   We will use same approach as find the height of the tree.
-   As we know every time we know the height of the left and right subtree, so we can calculate the diameter of the tree at this point.
-   Just keep track of the maximum diameter of the tree in height of BT code.
-   **Time complexity: O(N)**
-   **Space complexity: O(N)**

### Code

```cpp
class Solution {
private:
    int height(TreeNode* root, int& ans)
    {
        if (root == NULL) return 0;

        int leftHeight = height(root->left, ans);
        int rightHeight = height(root->right, ans);
        // keep track of the maximum diameter of the tree
        ans = max(ans, leftHeight + rightHeight);
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
