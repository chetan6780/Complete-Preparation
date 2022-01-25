# [515. Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) 🌟🌟

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

### This question is in continuation with **A general approach to level order traversal questions** series.

**Previous Questions**

1. [Binary tree level order traversal](./102_btLevelOrderTraversal.md)
2. [Binary tree level order traversal - II](./107_btLevelOrderTraversalII.md)
3. [Binary tree zig-zag level order traversal](./103_btZigzagLevelOrderTraversal.md)
4. [Average of levels](637_averageOfLevels.md)
5. [Binary tree right side view](./199_binaryTreeRightSideView.md)

### Recursive Solution

-   Self explanatory

### Code

```cpp
class Solution {
private:
    void largestValuesDFS(vector<int>& res, TreeNode* root, int level)
    {
        if (root == NULL)
            return;

        if (level == res.size()) // new value is max itself
            res.push_back(root->val);

        if (root->val > res[level]) // update max value
            res[level] = root->val;

        largestValuesDFS(res, root->left, level + 1);
        largestValuesDFS(res, root->right, level + 1);
    }

public:
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        largestValuesDFS(res, root, 0);
        return res;
    }
};
```

### Iterative solution

-   self explanatory

### Code

```cpp

class Solution {
public:
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            int mx = INT_MIN;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                if (node->val > mx) mx = node->val;
            }
            res.push_back(mx);
        }
        return res;
    }
};
```
