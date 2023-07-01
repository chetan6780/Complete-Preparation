# [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) 🌟🌟

Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

-   [Code studio problem link](https://www.codingninjas.com/studio/problems/975497?topList=striver-sde-sheet-problems)

### Brute force

-   For every node calculate the height of the left subtree and right subtree.
-   If the difference between the height of the left subtree and right subtree is greater than 1, return false.
-   Else return true.
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
public:

        bool isBalanced(TreeNode* root)
        {
            if (root == NULL) return true;
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);

            if (abs(leftHeight - rightHeight) > 1) return false;

            return isBalanced(root->left) && isBalanced(root->right);
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
int heightOfBt(BinaryTreeNode<int>* root)
{
    if (!root) return 0;

    int lh = heightOfBt(root->left);
    if (lh == -1) return -1;

    int rh = heightOfBt(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool isBalancedBT(BinaryTreeNode<int>* root)
{
    if (!root) return true;
    return heightOfBt(root) != -1;
}
```
