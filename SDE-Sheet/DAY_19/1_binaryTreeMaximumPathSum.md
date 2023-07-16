# [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/) 🌟🌟🌟

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

### Solution

-   There are three ways to get max path sum
    1. Get max sum of left + max sum of right + current root's value(gotAnswer)
    2. Didn't got the answer, take max of (left, right) + current root's value(takeOneWithRoot)
    3. left and right are negative so we will not take any of those, take only current root's value(onlyRoot)
-   Final result will be max(maxResult, gotAnswer, takeOneWithRoot, onlyRoot)
-   return max(takeOneWithRoot, onlyRoot)

### Code
```cpp
class Solution {
    int maxPathDown(TreeNode* node, int& mx)
    {
        if (node == NULL)return 0;
        int left = maxPathDown(node->left, mx);
        int right = maxPathDown(node->right, mx);

        int gotAnswer = left + right + node->val;
        int takeOneWithRoot = max(left, right) + node->val;
        int onlyRoot = node->val;

        mx = max({ mx, gotAnswer, takeOneWithRoot, onlyRoot });

        return max(takeOneWithRoot, onlyRoot);
    }

public:
    int maxPathSum(TreeNode* root)
    {
        int mx = INT_MIN;
        maxPathDown(root, mx);
        return mx;
    }
};
```