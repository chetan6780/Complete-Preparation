# [2265. Count Nodes Equal to Average of Subtree](https://leetcode-cn.com/problems/count-nodes-equal-to-average-of-subtree/) 🌟🌟

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

-   The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
-   A subtree of root is a tree consisting of root and all of its descendants.

### Brute Force

-   For every root, calculate the sum of its subtree and the number of nodes in its subtree.
-   If the average is equal to the value of the node, increase the answer by 1.
-   Do same for left and right subtree.
-   **Time Complexity:** O(N^2)
-   **Space Complexity:** O(1), ignoring recursion stack.

### Code

```cpp
class Solution {
private:
    int getSum(TreeNode* root, int& count)
    {
        if (root == NULL) return 0;
        count++;
        int lSum = getSum(root->left, count);
        int rSum = getSum(root->right, count);
        return lSum + rSum + root->val;
    }

public:
    int ans = 0;
    int averageOfSubtree(TreeNode* root)
    {
        if (root == NULL) return 0;

        int count = 0;
        int sum = getSum(root, count);
        if (root->val == sum / count) ans++;

        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return ans;
    }
};
```

### Optimized Solution

-   In brute force solution, we are calculating the sum of subtree for every node.
-   What if we start from the leaf nodes(kind of postorder traversal) and return {sum, count} to its parent.
-   now for current root we have sum and count of its left and right subtree.
-   we can simply calculate avg and check if it is equal to root->val and increase the answer by 1.
-   return {sum, count} to its parent, for calculating avg of its parent.
-   **Time Complexity:** O(N)
-   **Space Complexity:** O(1), ignoring recursion stack.

### Code

```cpp
class Solution {
    int result;
    pair<int, int> getSumAndCount(TreeNode* root)
    {
        if (root == nullptr) { return { 0, 0 }; }
        auto [leftSum, leftCount] = getSumAndCount(root->left);
        auto [rightSum, rightCount] = getSumAndCount(root->right);

        int sum = leftSum + rightSum + root->val;
        int count = leftCount + rightCount + 1;
        int avg = sum / count;

        if (avg == root->val) result++;

        return { sum, count };
    }

public:
    int averageOfSubtree(TreeNode* root)
    {
        result = 0;
        getSumAndCount(root);
        return result;
    }
};
```
